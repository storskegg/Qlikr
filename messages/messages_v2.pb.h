// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messages_v2.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_messages_5fv2_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_messages_5fv2_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_messages_5fv2_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_messages_5fv2_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_messages_5fv2_2eproto;
namespace messages2 {
class GarageDoorMessage;
class GarageDoorMessageDefaultTypeInternal;
extern GarageDoorMessageDefaultTypeInternal _GarageDoorMessage_default_instance_;
class HotpHmacCreds;
class HotpHmacCredsDefaultTypeInternal;
extern HotpHmacCredsDefaultTypeInternal _HotpHmacCreds_default_instance_;
}  // namespace messages2
PROTOBUF_NAMESPACE_OPEN
template<> ::messages2::GarageDoorMessage* Arena::CreateMaybeMessage<::messages2::GarageDoorMessage>(Arena*);
template<> ::messages2::HotpHmacCreds* Arena::CreateMaybeMessage<::messages2::HotpHmacCreds>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace messages2 {

enum GarageDoorMessage_MessageType : int {
  GarageDoorMessage_MessageType_OPEN = 0,
  GarageDoorMessage_MessageType_RECVD = 1,
  GarageDoorMessage_MessageType_ACCEPTED = 10,
  GarageDoorMessage_MessageType_ACCEPTED_OPENING = 11,
  GarageDoorMessage_MessageType_ACCEPTED_CLOSING = 12,
  GarageDoorMessage_MessageType_DENIED = 40,
  GarageDoorMessage_MessageType_DENIED_UNAUTH = 41,
  GarageDoorMessage_MessageType_DENIED_REVOKED = 42,
  GarageDoorMessage_MessageType_DENIED_OOB_COUNT = 43,
  GarageDoorMessage_MessageType_DENIED_OOB_GEOFENCE = 44,
  GarageDoorMessage_MessageType_GarageDoorMessage_MessageType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  GarageDoorMessage_MessageType_GarageDoorMessage_MessageType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool GarageDoorMessage_MessageType_IsValid(int value);
constexpr GarageDoorMessage_MessageType GarageDoorMessage_MessageType_MessageType_MIN = GarageDoorMessage_MessageType_OPEN;
constexpr GarageDoorMessage_MessageType GarageDoorMessage_MessageType_MessageType_MAX = GarageDoorMessage_MessageType_DENIED_OOB_GEOFENCE;
constexpr int GarageDoorMessage_MessageType_MessageType_ARRAYSIZE = GarageDoorMessage_MessageType_MessageType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* GarageDoorMessage_MessageType_descriptor();
template<typename T>
inline const std::string& GarageDoorMessage_MessageType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, GarageDoorMessage_MessageType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function GarageDoorMessage_MessageType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    GarageDoorMessage_MessageType_descriptor(), enum_t_value);
}
inline bool GarageDoorMessage_MessageType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, GarageDoorMessage_MessageType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<GarageDoorMessage_MessageType>(
    GarageDoorMessage_MessageType_descriptor(), name, value);
}
// ===================================================================

class HotpHmacCreds PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:messages2.HotpHmacCreds) */ {
 public:
  inline HotpHmacCreds() : HotpHmacCreds(nullptr) {}
  virtual ~HotpHmacCreds();

  HotpHmacCreds(const HotpHmacCreds& from);
  HotpHmacCreds(HotpHmacCreds&& from) noexcept
    : HotpHmacCreds() {
    *this = ::std::move(from);
  }

  inline HotpHmacCreds& operator=(const HotpHmacCreds& from) {
    CopyFrom(from);
    return *this;
  }
  inline HotpHmacCreds& operator=(HotpHmacCreds&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const HotpHmacCreds& default_instance();

  static inline const HotpHmacCreds* internal_default_instance() {
    return reinterpret_cast<const HotpHmacCreds*>(
               &_HotpHmacCreds_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(HotpHmacCreds& a, HotpHmacCreds& b) {
    a.Swap(&b);
  }
  inline void Swap(HotpHmacCreds* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HotpHmacCreds* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline HotpHmacCreds* New() const final {
    return CreateMaybeMessage<HotpHmacCreds>(nullptr);
  }

  HotpHmacCreds* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<HotpHmacCreds>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const HotpHmacCreds& from);
  void MergeFrom(const HotpHmacCreds& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HotpHmacCreds* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "messages2.HotpHmacCreds";
  }
  protected:
  explicit HotpHmacCreds(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_messages_5fv2_2eproto);
    return ::descriptor_table_messages_5fv2_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNonceFieldNumber = 1,
    kSignatureFieldNumber = 2,
  };
  // bytes nonce = 1;
  void clear_nonce();
  const std::string& nonce() const;
  void set_nonce(const std::string& value);
  void set_nonce(std::string&& value);
  void set_nonce(const char* value);
  void set_nonce(const void* value, size_t size);
  std::string* mutable_nonce();
  std::string* release_nonce();
  void set_allocated_nonce(std::string* nonce);
  private:
  const std::string& _internal_nonce() const;
  void _internal_set_nonce(const std::string& value);
  std::string* _internal_mutable_nonce();
  public:

  // bytes signature = 2;
  void clear_signature();
  const std::string& signature() const;
  void set_signature(const std::string& value);
  void set_signature(std::string&& value);
  void set_signature(const char* value);
  void set_signature(const void* value, size_t size);
  std::string* mutable_signature();
  std::string* release_signature();
  void set_allocated_signature(std::string* signature);
  private:
  const std::string& _internal_signature() const;
  void _internal_set_signature(const std::string& value);
  std::string* _internal_mutable_signature();
  public:

  // @@protoc_insertion_point(class_scope:messages2.HotpHmacCreds)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr nonce_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr signature_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_messages_5fv2_2eproto;
};
// -------------------------------------------------------------------

class GarageDoorMessage PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:messages2.GarageDoorMessage) */ {
 public:
  inline GarageDoorMessage() : GarageDoorMessage(nullptr) {}
  virtual ~GarageDoorMessage();

  GarageDoorMessage(const GarageDoorMessage& from);
  GarageDoorMessage(GarageDoorMessage&& from) noexcept
    : GarageDoorMessage() {
    *this = ::std::move(from);
  }

  inline GarageDoorMessage& operator=(const GarageDoorMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline GarageDoorMessage& operator=(GarageDoorMessage&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const GarageDoorMessage& default_instance();

  static inline const GarageDoorMessage* internal_default_instance() {
    return reinterpret_cast<const GarageDoorMessage*>(
               &_GarageDoorMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(GarageDoorMessage& a, GarageDoorMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(GarageDoorMessage* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GarageDoorMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GarageDoorMessage* New() const final {
    return CreateMaybeMessage<GarageDoorMessage>(nullptr);
  }

  GarageDoorMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GarageDoorMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GarageDoorMessage& from);
  void MergeFrom(const GarageDoorMessage& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GarageDoorMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "messages2.GarageDoorMessage";
  }
  protected:
  explicit GarageDoorMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_messages_5fv2_2eproto);
    return ::descriptor_table_messages_5fv2_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef GarageDoorMessage_MessageType MessageType;
  static constexpr MessageType OPEN =
    GarageDoorMessage_MessageType_OPEN;
  static constexpr MessageType RECVD =
    GarageDoorMessage_MessageType_RECVD;
  static constexpr MessageType ACCEPTED =
    GarageDoorMessage_MessageType_ACCEPTED;
  static constexpr MessageType ACCEPTED_OPENING =
    GarageDoorMessage_MessageType_ACCEPTED_OPENING;
  static constexpr MessageType ACCEPTED_CLOSING =
    GarageDoorMessage_MessageType_ACCEPTED_CLOSING;
  static constexpr MessageType DENIED =
    GarageDoorMessage_MessageType_DENIED;
  static constexpr MessageType DENIED_UNAUTH =
    GarageDoorMessage_MessageType_DENIED_UNAUTH;
  static constexpr MessageType DENIED_REVOKED =
    GarageDoorMessage_MessageType_DENIED_REVOKED;
  static constexpr MessageType DENIED_OOB_COUNT =
    GarageDoorMessage_MessageType_DENIED_OOB_COUNT;
  static constexpr MessageType DENIED_OOB_GEOFENCE =
    GarageDoorMessage_MessageType_DENIED_OOB_GEOFENCE;
  static inline bool MessageType_IsValid(int value) {
    return GarageDoorMessage_MessageType_IsValid(value);
  }
  static constexpr MessageType MessageType_MIN =
    GarageDoorMessage_MessageType_MessageType_MIN;
  static constexpr MessageType MessageType_MAX =
    GarageDoorMessage_MessageType_MessageType_MAX;
  static constexpr int MessageType_ARRAYSIZE =
    GarageDoorMessage_MessageType_MessageType_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  MessageType_descriptor() {
    return GarageDoorMessage_MessageType_descriptor();
  }
  template<typename T>
  static inline const std::string& MessageType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, MessageType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function MessageType_Name.");
    return GarageDoorMessage_MessageType_Name(enum_t_value);
  }
  static inline bool MessageType_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      MessageType* value) {
    return GarageDoorMessage_MessageType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
    kNmeaFieldNumber = 6,
    kCredsFieldNumber = 3,
    kTypeFieldNumber = 2,
  };
  // string id = 1;
  void clear_id();
  const std::string& id() const;
  void set_id(const std::string& value);
  void set_id(std::string&& value);
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  std::string* mutable_id();
  std::string* release_id();
  void set_allocated_id(std::string* id);
  private:
  const std::string& _internal_id() const;
  void _internal_set_id(const std::string& value);
  std::string* _internal_mutable_id();
  public:

  // bytes nmea = 6;
  void clear_nmea();
  const std::string& nmea() const;
  void set_nmea(const std::string& value);
  void set_nmea(std::string&& value);
  void set_nmea(const char* value);
  void set_nmea(const void* value, size_t size);
  std::string* mutable_nmea();
  std::string* release_nmea();
  void set_allocated_nmea(std::string* nmea);
  private:
  const std::string& _internal_nmea() const;
  void _internal_set_nmea(const std::string& value);
  std::string* _internal_mutable_nmea();
  public:

  // .messages2.HotpHmacCreds creds = 3;
  bool has_creds() const;
  private:
  bool _internal_has_creds() const;
  public:
  void clear_creds();
  const ::messages2::HotpHmacCreds& creds() const;
  ::messages2::HotpHmacCreds* release_creds();
  ::messages2::HotpHmacCreds* mutable_creds();
  void set_allocated_creds(::messages2::HotpHmacCreds* creds);
  private:
  const ::messages2::HotpHmacCreds& _internal_creds() const;
  ::messages2::HotpHmacCreds* _internal_mutable_creds();
  public:
  void unsafe_arena_set_allocated_creds(
      ::messages2::HotpHmacCreds* creds);
  ::messages2::HotpHmacCreds* unsafe_arena_release_creds();

  // .messages2.GarageDoorMessage.MessageType type = 2;
  void clear_type();
  ::messages2::GarageDoorMessage_MessageType type() const;
  void set_type(::messages2::GarageDoorMessage_MessageType value);
  private:
  ::messages2::GarageDoorMessage_MessageType _internal_type() const;
  void _internal_set_type(::messages2::GarageDoorMessage_MessageType value);
  public:

  // @@protoc_insertion_point(class_scope:messages2.GarageDoorMessage)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr nmea_;
  ::messages2::HotpHmacCreds* creds_;
  int type_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_messages_5fv2_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HotpHmacCreds

// bytes nonce = 1;
inline void HotpHmacCreds::clear_nonce() {
  nonce_.ClearToEmpty();
}
inline const std::string& HotpHmacCreds::nonce() const {
  // @@protoc_insertion_point(field_get:messages2.HotpHmacCreds.nonce)
  return _internal_nonce();
}
inline void HotpHmacCreds::set_nonce(const std::string& value) {
  _internal_set_nonce(value);
  // @@protoc_insertion_point(field_set:messages2.HotpHmacCreds.nonce)
}
inline std::string* HotpHmacCreds::mutable_nonce() {
  // @@protoc_insertion_point(field_mutable:messages2.HotpHmacCreds.nonce)
  return _internal_mutable_nonce();
}
inline const std::string& HotpHmacCreds::_internal_nonce() const {
  return nonce_.Get();
}
inline void HotpHmacCreds::_internal_set_nonce(const std::string& value) {
  
  nonce_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void HotpHmacCreds::set_nonce(std::string&& value) {
  
  nonce_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:messages2.HotpHmacCreds.nonce)
}
inline void HotpHmacCreds::set_nonce(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  nonce_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:messages2.HotpHmacCreds.nonce)
}
inline void HotpHmacCreds::set_nonce(const void* value,
    size_t size) {
  
  nonce_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:messages2.HotpHmacCreds.nonce)
}
inline std::string* HotpHmacCreds::_internal_mutable_nonce() {
  
  return nonce_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* HotpHmacCreds::release_nonce() {
  // @@protoc_insertion_point(field_release:messages2.HotpHmacCreds.nonce)
  return nonce_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void HotpHmacCreds::set_allocated_nonce(std::string* nonce) {
  if (nonce != nullptr) {
    
  } else {
    
  }
  nonce_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), nonce,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:messages2.HotpHmacCreds.nonce)
}

// bytes signature = 2;
inline void HotpHmacCreds::clear_signature() {
  signature_.ClearToEmpty();
}
inline const std::string& HotpHmacCreds::signature() const {
  // @@protoc_insertion_point(field_get:messages2.HotpHmacCreds.signature)
  return _internal_signature();
}
inline void HotpHmacCreds::set_signature(const std::string& value) {
  _internal_set_signature(value);
  // @@protoc_insertion_point(field_set:messages2.HotpHmacCreds.signature)
}
inline std::string* HotpHmacCreds::mutable_signature() {
  // @@protoc_insertion_point(field_mutable:messages2.HotpHmacCreds.signature)
  return _internal_mutable_signature();
}
inline const std::string& HotpHmacCreds::_internal_signature() const {
  return signature_.Get();
}
inline void HotpHmacCreds::_internal_set_signature(const std::string& value) {
  
  signature_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void HotpHmacCreds::set_signature(std::string&& value) {
  
  signature_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:messages2.HotpHmacCreds.signature)
}
inline void HotpHmacCreds::set_signature(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  signature_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:messages2.HotpHmacCreds.signature)
}
inline void HotpHmacCreds::set_signature(const void* value,
    size_t size) {
  
  signature_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:messages2.HotpHmacCreds.signature)
}
inline std::string* HotpHmacCreds::_internal_mutable_signature() {
  
  return signature_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* HotpHmacCreds::release_signature() {
  // @@protoc_insertion_point(field_release:messages2.HotpHmacCreds.signature)
  return signature_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void HotpHmacCreds::set_allocated_signature(std::string* signature) {
  if (signature != nullptr) {
    
  } else {
    
  }
  signature_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), signature,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:messages2.HotpHmacCreds.signature)
}

// -------------------------------------------------------------------

// GarageDoorMessage

// string id = 1;
inline void GarageDoorMessage::clear_id() {
  id_.ClearToEmpty();
}
inline const std::string& GarageDoorMessage::id() const {
  // @@protoc_insertion_point(field_get:messages2.GarageDoorMessage.id)
  return _internal_id();
}
inline void GarageDoorMessage::set_id(const std::string& value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:messages2.GarageDoorMessage.id)
}
inline std::string* GarageDoorMessage::mutable_id() {
  // @@protoc_insertion_point(field_mutable:messages2.GarageDoorMessage.id)
  return _internal_mutable_id();
}
inline const std::string& GarageDoorMessage::_internal_id() const {
  return id_.Get();
}
inline void GarageDoorMessage::_internal_set_id(const std::string& value) {
  
  id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void GarageDoorMessage::set_id(std::string&& value) {
  
  id_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:messages2.GarageDoorMessage.id)
}
inline void GarageDoorMessage::set_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:messages2.GarageDoorMessage.id)
}
inline void GarageDoorMessage::set_id(const char* value,
    size_t size) {
  
  id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:messages2.GarageDoorMessage.id)
}
inline std::string* GarageDoorMessage::_internal_mutable_id() {
  
  return id_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* GarageDoorMessage::release_id() {
  // @@protoc_insertion_point(field_release:messages2.GarageDoorMessage.id)
  return id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void GarageDoorMessage::set_allocated_id(std::string* id) {
  if (id != nullptr) {
    
  } else {
    
  }
  id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), id,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:messages2.GarageDoorMessage.id)
}

// .messages2.GarageDoorMessage.MessageType type = 2;
inline void GarageDoorMessage::clear_type() {
  type_ = 0;
}
inline ::messages2::GarageDoorMessage_MessageType GarageDoorMessage::_internal_type() const {
  return static_cast< ::messages2::GarageDoorMessage_MessageType >(type_);
}
inline ::messages2::GarageDoorMessage_MessageType GarageDoorMessage::type() const {
  // @@protoc_insertion_point(field_get:messages2.GarageDoorMessage.type)
  return _internal_type();
}
inline void GarageDoorMessage::_internal_set_type(::messages2::GarageDoorMessage_MessageType value) {
  
  type_ = value;
}
inline void GarageDoorMessage::set_type(::messages2::GarageDoorMessage_MessageType value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:messages2.GarageDoorMessage.type)
}

// .messages2.HotpHmacCreds creds = 3;
inline bool GarageDoorMessage::_internal_has_creds() const {
  return this != internal_default_instance() && creds_ != nullptr;
}
inline bool GarageDoorMessage::has_creds() const {
  return _internal_has_creds();
}
inline void GarageDoorMessage::clear_creds() {
  if (GetArena() == nullptr && creds_ != nullptr) {
    delete creds_;
  }
  creds_ = nullptr;
}
inline const ::messages2::HotpHmacCreds& GarageDoorMessage::_internal_creds() const {
  const ::messages2::HotpHmacCreds* p = creds_;
  return p != nullptr ? *p : reinterpret_cast<const ::messages2::HotpHmacCreds&>(
      ::messages2::_HotpHmacCreds_default_instance_);
}
inline const ::messages2::HotpHmacCreds& GarageDoorMessage::creds() const {
  // @@protoc_insertion_point(field_get:messages2.GarageDoorMessage.creds)
  return _internal_creds();
}
inline void GarageDoorMessage::unsafe_arena_set_allocated_creds(
    ::messages2::HotpHmacCreds* creds) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(creds_);
  }
  creds_ = creds;
  if (creds) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:messages2.GarageDoorMessage.creds)
}
inline ::messages2::HotpHmacCreds* GarageDoorMessage::release_creds() {
  
  ::messages2::HotpHmacCreds* temp = creds_;
  creds_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::messages2::HotpHmacCreds* GarageDoorMessage::unsafe_arena_release_creds() {
  // @@protoc_insertion_point(field_release:messages2.GarageDoorMessage.creds)
  
  ::messages2::HotpHmacCreds* temp = creds_;
  creds_ = nullptr;
  return temp;
}
inline ::messages2::HotpHmacCreds* GarageDoorMessage::_internal_mutable_creds() {
  
  if (creds_ == nullptr) {
    auto* p = CreateMaybeMessage<::messages2::HotpHmacCreds>(GetArena());
    creds_ = p;
  }
  return creds_;
}
inline ::messages2::HotpHmacCreds* GarageDoorMessage::mutable_creds() {
  // @@protoc_insertion_point(field_mutable:messages2.GarageDoorMessage.creds)
  return _internal_mutable_creds();
}
inline void GarageDoorMessage::set_allocated_creds(::messages2::HotpHmacCreds* creds) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete creds_;
  }
  if (creds) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(creds);
    if (message_arena != submessage_arena) {
      creds = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, creds, submessage_arena);
    }
    
  } else {
    
  }
  creds_ = creds;
  // @@protoc_insertion_point(field_set_allocated:messages2.GarageDoorMessage.creds)
}

// bytes nmea = 6;
inline void GarageDoorMessage::clear_nmea() {
  nmea_.ClearToEmpty();
}
inline const std::string& GarageDoorMessage::nmea() const {
  // @@protoc_insertion_point(field_get:messages2.GarageDoorMessage.nmea)
  return _internal_nmea();
}
inline void GarageDoorMessage::set_nmea(const std::string& value) {
  _internal_set_nmea(value);
  // @@protoc_insertion_point(field_set:messages2.GarageDoorMessage.nmea)
}
inline std::string* GarageDoorMessage::mutable_nmea() {
  // @@protoc_insertion_point(field_mutable:messages2.GarageDoorMessage.nmea)
  return _internal_mutable_nmea();
}
inline const std::string& GarageDoorMessage::_internal_nmea() const {
  return nmea_.Get();
}
inline void GarageDoorMessage::_internal_set_nmea(const std::string& value) {
  
  nmea_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void GarageDoorMessage::set_nmea(std::string&& value) {
  
  nmea_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:messages2.GarageDoorMessage.nmea)
}
inline void GarageDoorMessage::set_nmea(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  nmea_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:messages2.GarageDoorMessage.nmea)
}
inline void GarageDoorMessage::set_nmea(const void* value,
    size_t size) {
  
  nmea_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:messages2.GarageDoorMessage.nmea)
}
inline std::string* GarageDoorMessage::_internal_mutable_nmea() {
  
  return nmea_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* GarageDoorMessage::release_nmea() {
  // @@protoc_insertion_point(field_release:messages2.GarageDoorMessage.nmea)
  return nmea_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void GarageDoorMessage::set_allocated_nmea(std::string* nmea) {
  if (nmea != nullptr) {
    
  } else {
    
  }
  nmea_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), nmea,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:messages2.GarageDoorMessage.nmea)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace messages2

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::messages2::GarageDoorMessage_MessageType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::messages2::GarageDoorMessage_MessageType>() {
  return ::messages2::GarageDoorMessage_MessageType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_messages_5fv2_2eproto