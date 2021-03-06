// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: action.proto

#ifndef PROTOBUF_INCLUDED_action_2eproto
#define PROTOBUF_INCLUDED_action_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_action_2eproto 

namespace protobuf_action_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_action_2eproto
namespace gameplay {
class EventPacket;
class EventPacketDefaultTypeInternal;
extern EventPacketDefaultTypeInternal _EventPacket_default_instance_;
}  // namespace gameplay
namespace google {
namespace protobuf {
template<> ::gameplay::EventPacket* Arena::CreateMaybeMessage<::gameplay::EventPacket>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace gameplay {

enum EventPacket_ActionType {
  EventPacket_ActionType_MOVE = 0,
  EventPacket_ActionType_ATTACK = 1,
  EventPacket_ActionType_EventPacket_ActionType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EventPacket_ActionType_EventPacket_ActionType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EventPacket_ActionType_IsValid(int value);
const EventPacket_ActionType EventPacket_ActionType_ActionType_MIN = EventPacket_ActionType_MOVE;
const EventPacket_ActionType EventPacket_ActionType_ActionType_MAX = EventPacket_ActionType_ATTACK;
const int EventPacket_ActionType_ActionType_ARRAYSIZE = EventPacket_ActionType_ActionType_MAX + 1;

const ::google::protobuf::EnumDescriptor* EventPacket_ActionType_descriptor();
inline const ::std::string& EventPacket_ActionType_Name(EventPacket_ActionType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EventPacket_ActionType_descriptor(), value);
}
inline bool EventPacket_ActionType_Parse(
    const ::std::string& name, EventPacket_ActionType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EventPacket_ActionType>(
    EventPacket_ActionType_descriptor(), name, value);
}
// ===================================================================

class EventPacket : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:gameplay.EventPacket) */ {
 public:
  EventPacket();
  virtual ~EventPacket();

  EventPacket(const EventPacket& from);

  inline EventPacket& operator=(const EventPacket& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  EventPacket(EventPacket&& from) noexcept
    : EventPacket() {
    *this = ::std::move(from);
  }

  inline EventPacket& operator=(EventPacket&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const EventPacket& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EventPacket* internal_default_instance() {
    return reinterpret_cast<const EventPacket*>(
               &_EventPacket_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(EventPacket* other);
  friend void swap(EventPacket& a, EventPacket& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline EventPacket* New() const final {
    return CreateMaybeMessage<EventPacket>(NULL);
  }

  EventPacket* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<EventPacket>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const EventPacket& from);
  void MergeFrom(const EventPacket& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EventPacket* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef EventPacket_ActionType ActionType;
  static const ActionType MOVE =
    EventPacket_ActionType_MOVE;
  static const ActionType ATTACK =
    EventPacket_ActionType_ATTACK;
  static inline bool ActionType_IsValid(int value) {
    return EventPacket_ActionType_IsValid(value);
  }
  static const ActionType ActionType_MIN =
    EventPacket_ActionType_ActionType_MIN;
  static const ActionType ActionType_MAX =
    EventPacket_ActionType_ActionType_MAX;
  static const int ActionType_ARRAYSIZE =
    EventPacket_ActionType_ActionType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  ActionType_descriptor() {
    return EventPacket_ActionType_descriptor();
  }
  static inline const ::std::string& ActionType_Name(ActionType value) {
    return EventPacket_ActionType_Name(value);
  }
  static inline bool ActionType_Parse(const ::std::string& name,
      ActionType* value) {
    return EventPacket_ActionType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // int32 session_id = 1;
  void clear_session_id();
  static const int kSessionIdFieldNumber = 1;
  ::google::protobuf::int32 session_id() const;
  void set_session_id(::google::protobuf::int32 value);

  // .gameplay.EventPacket.ActionType type = 2;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::gameplay::EventPacket_ActionType type() const;
  void set_type(::gameplay::EventPacket_ActionType value);

  // float radius = 3;
  void clear_radius();
  static const int kRadiusFieldNumber = 3;
  float radius() const;
  void set_radius(float value);

  // float send_time = 4;
  void clear_send_time();
  static const int kSendTimeFieldNumber = 4;
  float send_time() const;
  void set_send_time(float value);

  // @@protoc_insertion_point(class_scope:gameplay.EventPacket)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 session_id_;
  int type_;
  float radius_;
  float send_time_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_action_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// EventPacket

// int32 session_id = 1;
inline void EventPacket::clear_session_id() {
  session_id_ = 0;
}
inline ::google::protobuf::int32 EventPacket::session_id() const {
  // @@protoc_insertion_point(field_get:gameplay.EventPacket.session_id)
  return session_id_;
}
inline void EventPacket::set_session_id(::google::protobuf::int32 value) {
  
  session_id_ = value;
  // @@protoc_insertion_point(field_set:gameplay.EventPacket.session_id)
}

// .gameplay.EventPacket.ActionType type = 2;
inline void EventPacket::clear_type() {
  type_ = 0;
}
inline ::gameplay::EventPacket_ActionType EventPacket::type() const {
  // @@protoc_insertion_point(field_get:gameplay.EventPacket.type)
  return static_cast< ::gameplay::EventPacket_ActionType >(type_);
}
inline void EventPacket::set_type(::gameplay::EventPacket_ActionType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:gameplay.EventPacket.type)
}

// float radius = 3;
inline void EventPacket::clear_radius() {
  radius_ = 0;
}
inline float EventPacket::radius() const {
  // @@protoc_insertion_point(field_get:gameplay.EventPacket.radius)
  return radius_;
}
inline void EventPacket::set_radius(float value) {
  
  radius_ = value;
  // @@protoc_insertion_point(field_set:gameplay.EventPacket.radius)
}

// float send_time = 4;
inline void EventPacket::clear_send_time() {
  send_time_ = 0;
}
inline float EventPacket::send_time() const {
  // @@protoc_insertion_point(field_get:gameplay.EventPacket.send_time)
  return send_time_;
}
inline void EventPacket::set_send_time(float value) {
  
  send_time_ = value;
  // @@protoc_insertion_point(field_set:gameplay.EventPacket.send_time)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace gameplay

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::gameplay::EventPacket_ActionType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::gameplay::EventPacket_ActionType>() {
  return ::gameplay::EventPacket_ActionType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_action_2eproto
