// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ICP.proto

#ifndef PROTOBUF_ICP_2eproto__INCLUDED
#define PROTOBUF_ICP_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace freerds {
namespace icp {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ICP_2eproto();
void protobuf_AssignDesc_ICP_2eproto();
void protobuf_ShutdownFile_ICP_2eproto();

class IsChannelAllowedRequest;
class IsChannelAllowedResponse;
class PingRequest;
class PingResponse;

enum MSGTYPE {
  IsChannelAllowed = 1,
  Ping = 2
};
bool MSGTYPE_IsValid(int value);
const MSGTYPE MSGTYPE_MIN = IsChannelAllowed;
const MSGTYPE MSGTYPE_MAX = Ping;
const int MSGTYPE_ARRAYSIZE = MSGTYPE_MAX + 1;

const ::google::protobuf::EnumDescriptor* MSGTYPE_descriptor();
inline const ::std::string& MSGTYPE_Name(MSGTYPE value) {
  return ::google::protobuf::internal::NameOfEnum(
    MSGTYPE_descriptor(), value);
}
inline bool MSGTYPE_Parse(
    const ::std::string& name, MSGTYPE* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MSGTYPE>(
    MSGTYPE_descriptor(), name, value);
}
// ===================================================================

class IsChannelAllowedRequest : public ::google::protobuf::Message {
 public:
  IsChannelAllowedRequest();
  virtual ~IsChannelAllowedRequest();
  
  IsChannelAllowedRequest(const IsChannelAllowedRequest& from);
  
  inline IsChannelAllowedRequest& operator=(const IsChannelAllowedRequest& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const IsChannelAllowedRequest& default_instance();
  
  void Swap(IsChannelAllowedRequest* other);
  
  // implements Message ----------------------------------------------
  
  IsChannelAllowedRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const IsChannelAllowedRequest& from);
  void MergeFrom(const IsChannelAllowedRequest& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string ChannelName = 1;
  inline bool has_channelname() const;
  inline void clear_channelname();
  static const int kChannelNameFieldNumber = 1;
  inline const ::std::string& channelname() const;
  inline void set_channelname(const ::std::string& value);
  inline void set_channelname(const char* value);
  inline void set_channelname(const char* value, size_t size);
  inline ::std::string* mutable_channelname();
  inline ::std::string* release_channelname();
  
  // @@protoc_insertion_point(class_scope:freerds.icp.IsChannelAllowedRequest)
 private:
  inline void set_has_channelname();
  inline void clear_has_channelname();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* channelname_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_ICP_2eproto();
  friend void protobuf_AssignDesc_ICP_2eproto();
  friend void protobuf_ShutdownFile_ICP_2eproto();
  
  void InitAsDefaultInstance();
  static IsChannelAllowedRequest* default_instance_;
};
// -------------------------------------------------------------------

class IsChannelAllowedResponse : public ::google::protobuf::Message {
 public:
  IsChannelAllowedResponse();
  virtual ~IsChannelAllowedResponse();
  
  IsChannelAllowedResponse(const IsChannelAllowedResponse& from);
  
  inline IsChannelAllowedResponse& operator=(const IsChannelAllowedResponse& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const IsChannelAllowedResponse& default_instance();
  
  void Swap(IsChannelAllowedResponse* other);
  
  // implements Message ----------------------------------------------
  
  IsChannelAllowedResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const IsChannelAllowedResponse& from);
  void MergeFrom(const IsChannelAllowedResponse& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required bool ChannelAllowed = 1;
  inline bool has_channelallowed() const;
  inline void clear_channelallowed();
  static const int kChannelAllowedFieldNumber = 1;
  inline bool channelallowed() const;
  inline void set_channelallowed(bool value);
  
  // @@protoc_insertion_point(class_scope:freerds.icp.IsChannelAllowedResponse)
 private:
  inline void set_has_channelallowed();
  inline void clear_has_channelallowed();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  bool channelallowed_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_ICP_2eproto();
  friend void protobuf_AssignDesc_ICP_2eproto();
  friend void protobuf_ShutdownFile_ICP_2eproto();
  
  void InitAsDefaultInstance();
  static IsChannelAllowedResponse* default_instance_;
};
// -------------------------------------------------------------------

class PingRequest : public ::google::protobuf::Message {
 public:
  PingRequest();
  virtual ~PingRequest();
  
  PingRequest(const PingRequest& from);
  
  inline PingRequest& operator=(const PingRequest& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const PingRequest& default_instance();
  
  void Swap(PingRequest* other);
  
  // implements Message ----------------------------------------------
  
  PingRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PingRequest& from);
  void MergeFrom(const PingRequest& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // @@protoc_insertion_point(class_scope:freerds.icp.PingRequest)
 private:
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];
  
  friend void  protobuf_AddDesc_ICP_2eproto();
  friend void protobuf_AssignDesc_ICP_2eproto();
  friend void protobuf_ShutdownFile_ICP_2eproto();
  
  void InitAsDefaultInstance();
  static PingRequest* default_instance_;
};
// -------------------------------------------------------------------

class PingResponse : public ::google::protobuf::Message {
 public:
  PingResponse();
  virtual ~PingResponse();
  
  PingResponse(const PingResponse& from);
  
  inline PingResponse& operator=(const PingResponse& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const PingResponse& default_instance();
  
  void Swap(PingResponse* other);
  
  // implements Message ----------------------------------------------
  
  PingResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PingResponse& from);
  void MergeFrom(const PingResponse& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required bool pong = 1;
  inline bool has_pong() const;
  inline void clear_pong();
  static const int kPongFieldNumber = 1;
  inline bool pong() const;
  inline void set_pong(bool value);
  
  // @@protoc_insertion_point(class_scope:freerds.icp.PingResponse)
 private:
  inline void set_has_pong();
  inline void clear_has_pong();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  bool pong_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_ICP_2eproto();
  friend void protobuf_AssignDesc_ICP_2eproto();
  friend void protobuf_ShutdownFile_ICP_2eproto();
  
  void InitAsDefaultInstance();
  static PingResponse* default_instance_;
};
// ===================================================================


// ===================================================================

// IsChannelAllowedRequest

// required string ChannelName = 1;
inline bool IsChannelAllowedRequest::has_channelname() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void IsChannelAllowedRequest::set_has_channelname() {
  _has_bits_[0] |= 0x00000001u;
}
inline void IsChannelAllowedRequest::clear_has_channelname() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void IsChannelAllowedRequest::clear_channelname() {
  if (channelname_ != &::google::protobuf::internal::kEmptyString) {
    channelname_->clear();
  }
  clear_has_channelname();
}
inline const ::std::string& IsChannelAllowedRequest::channelname() const {
  return *channelname_;
}
inline void IsChannelAllowedRequest::set_channelname(const ::std::string& value) {
  set_has_channelname();
  if (channelname_ == &::google::protobuf::internal::kEmptyString) {
    channelname_ = new ::std::string;
  }
  channelname_->assign(value);
}
inline void IsChannelAllowedRequest::set_channelname(const char* value) {
  set_has_channelname();
  if (channelname_ == &::google::protobuf::internal::kEmptyString) {
    channelname_ = new ::std::string;
  }
  channelname_->assign(value);
}
inline void IsChannelAllowedRequest::set_channelname(const char* value, size_t size) {
  set_has_channelname();
  if (channelname_ == &::google::protobuf::internal::kEmptyString) {
    channelname_ = new ::std::string;
  }
  channelname_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* IsChannelAllowedRequest::mutable_channelname() {
  set_has_channelname();
  if (channelname_ == &::google::protobuf::internal::kEmptyString) {
    channelname_ = new ::std::string;
  }
  return channelname_;
}
inline ::std::string* IsChannelAllowedRequest::release_channelname() {
  clear_has_channelname();
  if (channelname_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = channelname_;
    channelname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// -------------------------------------------------------------------

// IsChannelAllowedResponse

// required bool ChannelAllowed = 1;
inline bool IsChannelAllowedResponse::has_channelallowed() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void IsChannelAllowedResponse::set_has_channelallowed() {
  _has_bits_[0] |= 0x00000001u;
}
inline void IsChannelAllowedResponse::clear_has_channelallowed() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void IsChannelAllowedResponse::clear_channelallowed() {
  channelallowed_ = false;
  clear_has_channelallowed();
}
inline bool IsChannelAllowedResponse::channelallowed() const {
  return channelallowed_;
}
inline void IsChannelAllowedResponse::set_channelallowed(bool value) {
  set_has_channelallowed();
  channelallowed_ = value;
}

// -------------------------------------------------------------------

// PingRequest

// -------------------------------------------------------------------

// PingResponse

// required bool pong = 1;
inline bool PingResponse::has_pong() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PingResponse::set_has_pong() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PingResponse::clear_has_pong() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PingResponse::clear_pong() {
  pong_ = false;
  clear_has_pong();
}
inline bool PingResponse::pong() const {
  return pong_;
}
inline void PingResponse::set_pong(bool value) {
  set_has_pong();
  pong_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace icp
}  // namespace freerds

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< freerds::icp::MSGTYPE>() {
  return freerds::icp::MSGTYPE_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ICP_2eproto__INCLUDED
