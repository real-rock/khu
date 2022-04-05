# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: clientstreaming.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='clientstreaming.proto',
  package='clientstreaming',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x15\x63lientstreaming.proto\x12\x0f\x63lientstreaming\"\x1a\n\x07Message\x12\x0f\n\x07message\x18\x01 \x01(\t\"\x17\n\x06Number\x12\r\n\x05value\x18\x01 \x01(\x05\x32]\n\x0f\x43lientStreaming\x12J\n\x11GetServerResponse\x12\x18.clientstreaming.Message\x1a\x17.clientstreaming.Number\"\x00(\x01\x62\x06proto3'
)




_MESSAGE = _descriptor.Descriptor(
  name='Message',
  full_name='clientstreaming.Message',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='message', full_name='clientstreaming.Message.message', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=42,
  serialized_end=68,
)


_NUMBER = _descriptor.Descriptor(
  name='Number',
  full_name='clientstreaming.Number',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='value', full_name='clientstreaming.Number.value', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=70,
  serialized_end=93,
)

DESCRIPTOR.message_types_by_name['Message'] = _MESSAGE
DESCRIPTOR.message_types_by_name['Number'] = _NUMBER
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Message = _reflection.GeneratedProtocolMessageType('Message', (_message.Message,), {
  'DESCRIPTOR' : _MESSAGE,
  '__module__' : 'clientstreaming_pb2'
  # @@protoc_insertion_point(class_scope:clientstreaming.Message)
  })
_sym_db.RegisterMessage(Message)

Number = _reflection.GeneratedProtocolMessageType('Number', (_message.Message,), {
  'DESCRIPTOR' : _NUMBER,
  '__module__' : 'clientstreaming_pb2'
  # @@protoc_insertion_point(class_scope:clientstreaming.Number)
  })
_sym_db.RegisterMessage(Number)



_CLIENTSTREAMING = _descriptor.ServiceDescriptor(
  name='ClientStreaming',
  full_name='clientstreaming.ClientStreaming',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_start=95,
  serialized_end=188,
  methods=[
  _descriptor.MethodDescriptor(
    name='GetServerResponse',
    full_name='clientstreaming.ClientStreaming.GetServerResponse',
    index=0,
    containing_service=None,
    input_type=_MESSAGE,
    output_type=_NUMBER,
    serialized_options=None,
    create_key=_descriptor._internal_create_key,
  ),
])
_sym_db.RegisterServiceDescriptor(_CLIENTSTREAMING)

DESCRIPTOR.services_by_name['ClientStreaming'] = _CLIENTSTREAMING

# @@protoc_insertion_point(module_scope)
