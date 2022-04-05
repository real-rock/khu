package main

import (
	"log"
	"net/http"
)

func main() {
	// Create a server on port 8000
	// Exactly how you would run an HTTP/1.1 server
	srv := &http.Server{Addr: ":8000", Handler: http.HandlerFunc(handle)}

	// Start the server with TLS, since we are running HTTP/2 it must be
	// run with TLS.
	// Exactly how you would run an HTTP/1.1 server with TLS connection.
	log.Printf("Serving on https://0.0.0.0:8000")
	log.Fatal(srv.ListenAndServeTLS("server.crt", "server.key"))
}

func handle(w http.ResponseWriter, r *http.Request) {
	// Log the request protocol
	// More about http.Request: https://pkg.go.dev/net/http#Request
	log.Printf("Got connection: %s from %s", r.Proto, r.RemoteAddr)
	// Send a message back to the client
	w.Write([]byte("Hello"))
}
