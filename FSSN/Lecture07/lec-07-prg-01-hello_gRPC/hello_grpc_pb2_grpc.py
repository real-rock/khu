# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
"""Client and server classes corresponding to protobuf-defined services."""
import grpc

import hello_grpc_pb2 as hello__grpc__pb2


class MyServiceStub(object):
    """Missing associated documentation comment in .proto file."""

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.MyFunction = channel.unary_unary(
                '/MyService/MyFunction',
                request_serializer=hello__grpc__pb2.MyNumber.SerializeToString,
                response_deserializer=hello__grpc__pb2.MyNumber.FromString,
                )


class MyServiceServicer(object):
    """Missing associated documentation comment in .proto file."""

    def MyFunction(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_MyServiceServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'MyFunction': grpc.unary_unary_rpc_method_handler(
                    servicer.MyFunction,
                    request_deserializer=hello__grpc__pb2.MyNumber.FromString,
                    response_serializer=hello__grpc__pb2.MyNumber.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'MyService', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class MyService(object):
    """Missing associated documentation comment in .proto file."""

    @staticmethod
    def MyFunction(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/MyService/MyFunction',
            hello__grpc__pb2.MyNumber.SerializeToString,
            hello__grpc__pb2.MyNumber.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)