// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: person.proto

#ifndef PROTOBUF_person_2eproto__INCLUDED
#define PROTOBUF_person_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "animal.pb.h"
#include "house.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf_person_2eproto {
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
void InitDefaultsPersonImpl();
void InitDefaultsPerson();
inline void InitDefaults() {
  InitDefaultsPerson();
}
}  // namespace protobuf_person_2eproto
namespace pb {
namespace People {
class Person;
class PersonDefaultTypeInternal;
extern PersonDefaultTypeInternal _Person_default_instance_;
}  // namespace People
}  // namespace pb
namespace pb {
namespace People {

enum Person_SType {
  Person_SType_MALE = 0,
  Person_SType_FEMALE = 1,
  Person_SType_Person_SType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Person_SType_Person_SType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Person_SType_IsValid(int value);
const Person_SType Person_SType_SType_MIN = Person_SType_MALE;
const Person_SType Person_SType_SType_MAX = Person_SType_FEMALE;
const int Person_SType_SType_ARRAYSIZE = Person_SType_SType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Person_SType_descriptor();
inline const ::std::string& Person_SType_Name(Person_SType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Person_SType_descriptor(), value);
}
inline bool Person_SType_Parse(
    const ::std::string& name, Person_SType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Person_SType>(
    Person_SType_descriptor(), name, value);
}
// ===================================================================

class Person : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:pb.People.Person) */ {
 public:
  Person();
  virtual ~Person();

  Person(const Person& from);

  inline Person& operator=(const Person& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Person(Person&& from) noexcept
    : Person() {
    *this = ::std::move(from);
  }

  inline Person& operator=(Person&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Person& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Person* internal_default_instance() {
    return reinterpret_cast<const Person*>(
               &_Person_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Person* other);
  friend void swap(Person& a, Person& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Person* New() const PROTOBUF_FINAL { return New(NULL); }

  Person* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Person& from);
  void MergeFrom(const Person& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Person* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef Person_SType SType;
  static const SType MALE =
    Person_SType_MALE;
  static const SType FEMALE =
    Person_SType_FEMALE;
  static inline bool SType_IsValid(int value) {
    return Person_SType_IsValid(value);
  }
  static const SType SType_MIN =
    Person_SType_SType_MIN;
  static const SType SType_MAX =
    Person_SType_SType_MAX;
  static const int SType_ARRAYSIZE =
    Person_SType_SType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  SType_descriptor() {
    return Person_SType_descriptor();
  }
  static inline const ::std::string& SType_Name(SType value) {
    return Person_SType_Name(value);
  }
  static inline bool SType_Parse(const ::std::string& name,
      SType* value) {
    return Person_SType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // string email = 4;
  void clear_email();
  static const int kEmailFieldNumber = 4;
  const ::std::string& email() const;
  void set_email(const ::std::string& value);
  #if LANG_CXX11
  void set_email(::std::string&& value);
  #endif
  void set_email(const char* value);
  void set_email(const char* value, size_t size);
  ::std::string* mutable_email();
  ::std::string* release_email();
  void set_allocated_email(::std::string* email);

  // .pb.Animal.Dog dog = 5;
  bool has_dog() const;
  void clear_dog();
  static const int kDogFieldNumber = 5;
  const ::pb::Animal::Dog& dog() const;
  ::pb::Animal::Dog* release_dog();
  ::pb::Animal::Dog* mutable_dog();
  void set_allocated_dog(::pb::Animal::Dog* dog);

  // .pb.Environment.House house = 6;
  bool has_house() const;
  void clear_house();
  static const int kHouseFieldNumber = 6;
  const ::pb::Environment::House& house() const;
  ::pb::Environment::House* release_house();
  ::pb::Environment::House* mutable_house();
  void set_allocated_house(::pb::Environment::House* house);

  // int32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // .pb.People.Person.SType stype = 3;
  void clear_stype();
  static const int kStypeFieldNumber = 3;
  ::pb::People::Person_SType stype() const;
  void set_stype(::pb::People::Person_SType value);

  // @@protoc_insertion_point(class_scope:pb.People.Person)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr email_;
  ::pb::Animal::Dog* dog_;
  ::pb::Environment::House* house_;
  ::google::protobuf::int32 id_;
  int stype_;
  mutable int _cached_size_;
  friend struct ::protobuf_person_2eproto::TableStruct;
  friend void ::protobuf_person_2eproto::InitDefaultsPersonImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Person

// int32 id = 1;
inline void Person::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 Person::id() const {
  // @@protoc_insertion_point(field_get:pb.People.Person.id)
  return id_;
}
inline void Person::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:pb.People.Person.id)
}

// string name = 2;
inline void Person::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Person::name() const {
  // @@protoc_insertion_point(field_get:pb.People.Person.name)
  return name_.GetNoArena();
}
inline void Person::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:pb.People.Person.name)
}
#if LANG_CXX11
inline void Person::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:pb.People.Person.name)
}
#endif
inline void Person::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:pb.People.Person.name)
}
inline void Person::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:pb.People.Person.name)
}
inline ::std::string* Person::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:pb.People.Person.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Person::release_name() {
  // @@protoc_insertion_point(field_release:pb.People.Person.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Person::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:pb.People.Person.name)
}

// .pb.People.Person.SType stype = 3;
inline void Person::clear_stype() {
  stype_ = 0;
}
inline ::pb::People::Person_SType Person::stype() const {
  // @@protoc_insertion_point(field_get:pb.People.Person.stype)
  return static_cast< ::pb::People::Person_SType >(stype_);
}
inline void Person::set_stype(::pb::People::Person_SType value) {
  
  stype_ = value;
  // @@protoc_insertion_point(field_set:pb.People.Person.stype)
}

// string email = 4;
inline void Person::clear_email() {
  email_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Person::email() const {
  // @@protoc_insertion_point(field_get:pb.People.Person.email)
  return email_.GetNoArena();
}
inline void Person::set_email(const ::std::string& value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:pb.People.Person.email)
}
#if LANG_CXX11
inline void Person::set_email(::std::string&& value) {
  
  email_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:pb.People.Person.email)
}
#endif
inline void Person::set_email(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:pb.People.Person.email)
}
inline void Person::set_email(const char* value, size_t size) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:pb.People.Person.email)
}
inline ::std::string* Person::mutable_email() {
  
  // @@protoc_insertion_point(field_mutable:pb.People.Person.email)
  return email_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Person::release_email() {
  // @@protoc_insertion_point(field_release:pb.People.Person.email)
  
  return email_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Person::set_allocated_email(::std::string* email) {
  if (email != NULL) {
    
  } else {
    
  }
  email_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), email);
  // @@protoc_insertion_point(field_set_allocated:pb.People.Person.email)
}

// .pb.Animal.Dog dog = 5;
inline bool Person::has_dog() const {
  return this != internal_default_instance() && dog_ != NULL;
}
inline const ::pb::Animal::Dog& Person::dog() const {
  const ::pb::Animal::Dog* p = dog_;
  // @@protoc_insertion_point(field_get:pb.People.Person.dog)
  return p != NULL ? *p : *reinterpret_cast<const ::pb::Animal::Dog*>(
      &::pb::Animal::_Dog_default_instance_);
}
inline ::pb::Animal::Dog* Person::release_dog() {
  // @@protoc_insertion_point(field_release:pb.People.Person.dog)
  
  ::pb::Animal::Dog* temp = dog_;
  dog_ = NULL;
  return temp;
}
inline ::pb::Animal::Dog* Person::mutable_dog() {
  
  if (dog_ == NULL) {
    dog_ = new ::pb::Animal::Dog;
  }
  // @@protoc_insertion_point(field_mutable:pb.People.Person.dog)
  return dog_;
}
inline void Person::set_allocated_dog(::pb::Animal::Dog* dog) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(dog_);
  }
  if (dog) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      dog = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, dog, submessage_arena);
    }
    
  } else {
    
  }
  dog_ = dog;
  // @@protoc_insertion_point(field_set_allocated:pb.People.Person.dog)
}

// .pb.Environment.House house = 6;
inline bool Person::has_house() const {
  return this != internal_default_instance() && house_ != NULL;
}
inline const ::pb::Environment::House& Person::house() const {
  const ::pb::Environment::House* p = house_;
  // @@protoc_insertion_point(field_get:pb.People.Person.house)
  return p != NULL ? *p : *reinterpret_cast<const ::pb::Environment::House*>(
      &::pb::Environment::_House_default_instance_);
}
inline ::pb::Environment::House* Person::release_house() {
  // @@protoc_insertion_point(field_release:pb.People.Person.house)
  
  ::pb::Environment::House* temp = house_;
  house_ = NULL;
  return temp;
}
inline ::pb::Environment::House* Person::mutable_house() {
  
  if (house_ == NULL) {
    house_ = new ::pb::Environment::House;
  }
  // @@protoc_insertion_point(field_mutable:pb.People.Person.house)
  return house_;
}
inline void Person::set_allocated_house(::pb::Environment::House* house) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(house_);
  }
  if (house) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      house = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, house, submessage_arena);
    }
    
  } else {
    
  }
  house_ = house;
  // @@protoc_insertion_point(field_set_allocated:pb.People.Person.house)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace People
}  // namespace pb

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::pb::People::Person_SType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::pb::People::Person_SType>() {
  return ::pb::People::Person_SType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_person_2eproto__INCLUDED
