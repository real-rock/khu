package main

import (
	"github.com/zeromq/goczmq"
	"log"
)

func main() {
	r, err := goczmq.NewRouter("tcp://*:8080")
	if err != nil {
		log.Fatal(err)
	}
	defer r.Destroy()

	log.Println("router created and bound")
	d, err := goczmq.NewDealer("tcp://127.0.0.1:8080")
	if err != nil {
		log.Fatal(err)
	}
	if err = d.SendFrame([]byte("Hello"), goczmq.FlagNone); err != nil {
		log.Fatal(err)
	}
	req, err := r.RecvMessage()
	if err != nil {
		log.Print(err)
	} else {
		log.Printf("router received '%s' from '%v'", req[1], req[0])
	}
	if err = r.SendFrame([]byte("World"), goczmq.FlagNone); err != nil {
		log.Fatal(err)
	}
	reply, err := d.RecvMessage()
	if err != nil {
		log.Print(err)
	} else {
		log.Printf("received '%s'", string(reply[0]))
	}
}
