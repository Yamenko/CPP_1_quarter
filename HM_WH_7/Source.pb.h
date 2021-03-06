// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Source.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Source_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Source_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017001 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Source_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Source_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Source_2eproto;
namespace HW_7 {
class Student;
struct StudentDefaultTypeInternal;
extern StudentDefaultTypeInternal _Student_default_instance_;
class Student_FullName;
struct Student_FullNameDefaultTypeInternal;
extern Student_FullNameDefaultTypeInternal _Student_FullName_default_instance_;
class StudentsGroup;
struct StudentsGroupDefaultTypeInternal;
extern StudentsGroupDefaultTypeInternal _StudentsGroup_default_instance_;
}  // namespace HW_7
PROTOBUF_NAMESPACE_OPEN
template<> ::HW_7::Student* Arena::CreateMaybeMessage<::HW_7::Student>(Arena*);
template<> ::HW_7::Student_FullName* Arena::CreateMaybeMessage<::HW_7::Student_FullName>(Arena*);
template<> ::HW_7::StudentsGroup* Arena::CreateMaybeMessage<::HW_7::StudentsGroup>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace HW_7 {

// ===================================================================

class Student_FullName final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:HW_7.Student.FullName) */ {
 public:
  inline Student_FullName() : Student_FullName(nullptr) {}
  ~Student_FullName() override;
  explicit constexpr Student_FullName(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Student_FullName(const Student_FullName& from);
  Student_FullName(Student_FullName&& from) noexcept
    : Student_FullName() {
    *this = ::std::move(from);
  }

  inline Student_FullName& operator=(const Student_FullName& from) {
    CopyFrom(from);
    return *this;
  }
  inline Student_FullName& operator=(Student_FullName&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Student_FullName& default_instance() {
    return *internal_default_instance();
  }
  static inline const Student_FullName* internal_default_instance() {
    return reinterpret_cast<const Student_FullName*>(
               &_Student_FullName_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Student_FullName& a, Student_FullName& b) {
    a.Swap(&b);
  }
  inline void Swap(Student_FullName* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Student_FullName* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Student_FullName* New() const final {
    return new Student_FullName();
  }

  Student_FullName* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Student_FullName>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Student_FullName& from);
  void MergeFrom(const Student_FullName& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Student_FullName* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "HW_7.Student.FullName";
  }
  protected:
  explicit Student_FullName(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFirstNameFieldNumber = 1,
    kLastNameFieldNumber = 2,
    kMidleNameFieldNumber = 3,
  };
  // optional string firstName = 1;
  bool has_firstname() const;
  private:
  bool _internal_has_firstname() const;
  public:
  void clear_firstname();
  const std::string& firstname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_firstname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_firstname();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_firstname();
  void set_allocated_firstname(std::string* firstname);
  private:
  const std::string& _internal_firstname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_firstname(const std::string& value);
  std::string* _internal_mutable_firstname();
  public:

  // optional string lastName = 2;
  bool has_lastname() const;
  private:
  bool _internal_has_lastname() const;
  public:
  void clear_lastname();
  const std::string& lastname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_lastname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_lastname();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_lastname();
  void set_allocated_lastname(std::string* lastname);
  private:
  const std::string& _internal_lastname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_lastname(const std::string& value);
  std::string* _internal_mutable_lastname();
  public:

  // optional string midleName = 3;
  bool has_midlename() const;
  private:
  bool _internal_has_midlename() const;
  public:
  void clear_midlename();
  const std::string& midlename() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_midlename(ArgT0&& arg0, ArgT... args);
  std::string* mutable_midlename();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_midlename();
  void set_allocated_midlename(std::string* midlename);
  private:
  const std::string& _internal_midlename() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_midlename(const std::string& value);
  std::string* _internal_mutable_midlename();
  public:

  // @@protoc_insertion_point(class_scope:HW_7.Student.FullName)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr firstname_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr lastname_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr midlename_;
  friend struct ::TableStruct_Source_2eproto;
};
// -------------------------------------------------------------------

class Student final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:HW_7.Student) */ {
 public:
  inline Student() : Student(nullptr) {}
  ~Student() override;
  explicit constexpr Student(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Student(const Student& from);
  Student(Student&& from) noexcept
    : Student() {
    *this = ::std::move(from);
  }

  inline Student& operator=(const Student& from) {
    CopyFrom(from);
    return *this;
  }
  inline Student& operator=(Student&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Student& default_instance() {
    return *internal_default_instance();
  }
  static inline const Student* internal_default_instance() {
    return reinterpret_cast<const Student*>(
               &_Student_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Student& a, Student& b) {
    a.Swap(&b);
  }
  inline void Swap(Student* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Student* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Student* New() const final {
    return new Student();
  }

  Student* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Student>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Student& from);
  void MergeFrom(const Student& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Student* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "HW_7.Student";
  }
  protected:
  explicit Student(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Student_FullName FullName;

  // accessors -------------------------------------------------------

  enum : int {
    kNameStudentFieldNumber = 1,
    kMarksStudentFieldNumber = 2,
    kAverageMarkFieldNumber = 3,
  };
  // repeated .HW_7.Student.FullName nameStudent = 1;
  int namestudent_size() const;
  private:
  int _internal_namestudent_size() const;
  public:
  void clear_namestudent();
  ::HW_7::Student_FullName* mutable_namestudent(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::HW_7::Student_FullName >*
      mutable_namestudent();
  private:
  const ::HW_7::Student_FullName& _internal_namestudent(int index) const;
  ::HW_7::Student_FullName* _internal_add_namestudent();
  public:
  const ::HW_7::Student_FullName& namestudent(int index) const;
  ::HW_7::Student_FullName* add_namestudent();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::HW_7::Student_FullName >&
      namestudent() const;

  // repeated int32 marksStudent = 2;
  int marksstudent_size() const;
  private:
  int _internal_marksstudent_size() const;
  public:
  void clear_marksstudent();
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_marksstudent(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      _internal_marksstudent() const;
  void _internal_add_marksstudent(::PROTOBUF_NAMESPACE_ID::int32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      _internal_mutable_marksstudent();
  public:
  ::PROTOBUF_NAMESPACE_ID::int32 marksstudent(int index) const;
  void set_marksstudent(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_marksstudent(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      marksstudent() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_marksstudent();

  // optional float averageMark = 3;
  bool has_averagemark() const;
  private:
  bool _internal_has_averagemark() const;
  public:
  void clear_averagemark();
  float averagemark() const;
  void set_averagemark(float value);
  private:
  float _internal_averagemark() const;
  void _internal_set_averagemark(float value);
  public:

  // @@protoc_insertion_point(class_scope:HW_7.Student)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::HW_7::Student_FullName > namestudent_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > marksstudent_;
  mutable std::atomic<int> _marksstudent_cached_byte_size_;
  float averagemark_;
  friend struct ::TableStruct_Source_2eproto;
};
// -------------------------------------------------------------------

class StudentsGroup final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:HW_7.StudentsGroup) */ {
 public:
  inline StudentsGroup() : StudentsGroup(nullptr) {}
  ~StudentsGroup() override;
  explicit constexpr StudentsGroup(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  StudentsGroup(const StudentsGroup& from);
  StudentsGroup(StudentsGroup&& from) noexcept
    : StudentsGroup() {
    *this = ::std::move(from);
  }

  inline StudentsGroup& operator=(const StudentsGroup& from) {
    CopyFrom(from);
    return *this;
  }
  inline StudentsGroup& operator=(StudentsGroup&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const StudentsGroup& default_instance() {
    return *internal_default_instance();
  }
  static inline const StudentsGroup* internal_default_instance() {
    return reinterpret_cast<const StudentsGroup*>(
               &_StudentsGroup_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(StudentsGroup& a, StudentsGroup& b) {
    a.Swap(&b);
  }
  inline void Swap(StudentsGroup* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(StudentsGroup* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline StudentsGroup* New() const final {
    return new StudentsGroup();
  }

  StudentsGroup* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<StudentsGroup>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const StudentsGroup& from);
  void MergeFrom(const StudentsGroup& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StudentsGroup* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "HW_7.StudentsGroup";
  }
  protected:
  explicit StudentsGroup(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStudentsFieldNumber = 1,
  };
  // repeated .HW_7.Student students = 1;
  int students_size() const;
  private:
  int _internal_students_size() const;
  public:
  void clear_students();
  ::HW_7::Student* mutable_students(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::HW_7::Student >*
      mutable_students();
  private:
  const ::HW_7::Student& _internal_students(int index) const;
  ::HW_7::Student* _internal_add_students();
  public:
  const ::HW_7::Student& students(int index) const;
  ::HW_7::Student* add_students();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::HW_7::Student >&
      students() const;

  // @@protoc_insertion_point(class_scope:HW_7.StudentsGroup)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::HW_7::Student > students_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Source_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Student_FullName

// optional string firstName = 1;
inline bool Student_FullName::_internal_has_firstname() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Student_FullName::has_firstname() const {
  return _internal_has_firstname();
}
inline void Student_FullName::clear_firstname() {
  firstname_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Student_FullName::firstname() const {
  // @@protoc_insertion_point(field_get:HW_7.Student.FullName.firstName)
  return _internal_firstname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Student_FullName::set_firstname(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 firstname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:HW_7.Student.FullName.firstName)
}
inline std::string* Student_FullName::mutable_firstname() {
  // @@protoc_insertion_point(field_mutable:HW_7.Student.FullName.firstName)
  return _internal_mutable_firstname();
}
inline const std::string& Student_FullName::_internal_firstname() const {
  return firstname_.Get();
}
inline void Student_FullName::_internal_set_firstname(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  firstname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Student_FullName::_internal_mutable_firstname() {
  _has_bits_[0] |= 0x00000001u;
  return firstname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Student_FullName::release_firstname() {
  // @@protoc_insertion_point(field_release:HW_7.Student.FullName.firstName)
  if (!_internal_has_firstname()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return firstname_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Student_FullName::set_allocated_firstname(std::string* firstname) {
  if (firstname != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  firstname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), firstname,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:HW_7.Student.FullName.firstName)
}

// optional string lastName = 2;
inline bool Student_FullName::_internal_has_lastname() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Student_FullName::has_lastname() const {
  return _internal_has_lastname();
}
inline void Student_FullName::clear_lastname() {
  lastname_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& Student_FullName::lastname() const {
  // @@protoc_insertion_point(field_get:HW_7.Student.FullName.lastName)
  return _internal_lastname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Student_FullName::set_lastname(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000002u;
 lastname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:HW_7.Student.FullName.lastName)
}
inline std::string* Student_FullName::mutable_lastname() {
  // @@protoc_insertion_point(field_mutable:HW_7.Student.FullName.lastName)
  return _internal_mutable_lastname();
}
inline const std::string& Student_FullName::_internal_lastname() const {
  return lastname_.Get();
}
inline void Student_FullName::_internal_set_lastname(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  lastname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Student_FullName::_internal_mutable_lastname() {
  _has_bits_[0] |= 0x00000002u;
  return lastname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Student_FullName::release_lastname() {
  // @@protoc_insertion_point(field_release:HW_7.Student.FullName.lastName)
  if (!_internal_has_lastname()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return lastname_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Student_FullName::set_allocated_lastname(std::string* lastname) {
  if (lastname != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  lastname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), lastname,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:HW_7.Student.FullName.lastName)
}

// optional string midleName = 3;
inline bool Student_FullName::_internal_has_midlename() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool Student_FullName::has_midlename() const {
  return _internal_has_midlename();
}
inline void Student_FullName::clear_midlename() {
  midlename_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000004u;
}
inline const std::string& Student_FullName::midlename() const {
  // @@protoc_insertion_point(field_get:HW_7.Student.FullName.midleName)
  return _internal_midlename();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Student_FullName::set_midlename(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000004u;
 midlename_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:HW_7.Student.FullName.midleName)
}
inline std::string* Student_FullName::mutable_midlename() {
  // @@protoc_insertion_point(field_mutable:HW_7.Student.FullName.midleName)
  return _internal_mutable_midlename();
}
inline const std::string& Student_FullName::_internal_midlename() const {
  return midlename_.Get();
}
inline void Student_FullName::_internal_set_midlename(const std::string& value) {
  _has_bits_[0] |= 0x00000004u;
  midlename_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Student_FullName::_internal_mutable_midlename() {
  _has_bits_[0] |= 0x00000004u;
  return midlename_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Student_FullName::release_midlename() {
  // @@protoc_insertion_point(field_release:HW_7.Student.FullName.midleName)
  if (!_internal_has_midlename()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000004u;
  return midlename_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Student_FullName::set_allocated_midlename(std::string* midlename) {
  if (midlename != nullptr) {
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  midlename_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), midlename,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:HW_7.Student.FullName.midleName)
}

// -------------------------------------------------------------------

// Student

// repeated .HW_7.Student.FullName nameStudent = 1;
inline int Student::_internal_namestudent_size() const {
  return namestudent_.size();
}
inline int Student::namestudent_size() const {
  return _internal_namestudent_size();
}
inline void Student::clear_namestudent() {
  namestudent_.Clear();
}
inline ::HW_7::Student_FullName* Student::mutable_namestudent(int index) {
  // @@protoc_insertion_point(field_mutable:HW_7.Student.nameStudent)
  return namestudent_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::HW_7::Student_FullName >*
Student::mutable_namestudent() {
  // @@protoc_insertion_point(field_mutable_list:HW_7.Student.nameStudent)
  return &namestudent_;
}
inline const ::HW_7::Student_FullName& Student::_internal_namestudent(int index) const {
  return namestudent_.Get(index);
}
inline const ::HW_7::Student_FullName& Student::namestudent(int index) const {
  // @@protoc_insertion_point(field_get:HW_7.Student.nameStudent)
  return _internal_namestudent(index);
}
inline ::HW_7::Student_FullName* Student::_internal_add_namestudent() {
  return namestudent_.Add();
}
inline ::HW_7::Student_FullName* Student::add_namestudent() {
  // @@protoc_insertion_point(field_add:HW_7.Student.nameStudent)
  return _internal_add_namestudent();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::HW_7::Student_FullName >&
Student::namestudent() const {
  // @@protoc_insertion_point(field_list:HW_7.Student.nameStudent)
  return namestudent_;
}

// repeated int32 marksStudent = 2;
inline int Student::_internal_marksstudent_size() const {
  return marksstudent_.size();
}
inline int Student::marksstudent_size() const {
  return _internal_marksstudent_size();
}
inline void Student::clear_marksstudent() {
  marksstudent_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Student::_internal_marksstudent(int index) const {
  return marksstudent_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Student::marksstudent(int index) const {
  // @@protoc_insertion_point(field_get:HW_7.Student.marksStudent)
  return _internal_marksstudent(index);
}
inline void Student::set_marksstudent(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  marksstudent_.Set(index, value);
  // @@protoc_insertion_point(field_set:HW_7.Student.marksStudent)
}
inline void Student::_internal_add_marksstudent(::PROTOBUF_NAMESPACE_ID::int32 value) {
  marksstudent_.Add(value);
}
inline void Student::add_marksstudent(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_add_marksstudent(value);
  // @@protoc_insertion_point(field_add:HW_7.Student.marksStudent)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
Student::_internal_marksstudent() const {
  return marksstudent_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
Student::marksstudent() const {
  // @@protoc_insertion_point(field_list:HW_7.Student.marksStudent)
  return _internal_marksstudent();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
Student::_internal_mutable_marksstudent() {
  return &marksstudent_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
Student::mutable_marksstudent() {
  // @@protoc_insertion_point(field_mutable_list:HW_7.Student.marksStudent)
  return _internal_mutable_marksstudent();
}

// optional float averageMark = 3;
inline bool Student::_internal_has_averagemark() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Student::has_averagemark() const {
  return _internal_has_averagemark();
}
inline void Student::clear_averagemark() {
  averagemark_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline float Student::_internal_averagemark() const {
  return averagemark_;
}
inline float Student::averagemark() const {
  // @@protoc_insertion_point(field_get:HW_7.Student.averageMark)
  return _internal_averagemark();
}
inline void Student::_internal_set_averagemark(float value) {
  _has_bits_[0] |= 0x00000001u;
  averagemark_ = value;
}
inline void Student::set_averagemark(float value) {
  _internal_set_averagemark(value);
  // @@protoc_insertion_point(field_set:HW_7.Student.averageMark)
}

// -------------------------------------------------------------------

// StudentsGroup

// repeated .HW_7.Student students = 1;
inline int StudentsGroup::_internal_students_size() const {
  return students_.size();
}
inline int StudentsGroup::students_size() const {
  return _internal_students_size();
}
inline void StudentsGroup::clear_students() {
  students_.Clear();
}
inline ::HW_7::Student* StudentsGroup::mutable_students(int index) {
  // @@protoc_insertion_point(field_mutable:HW_7.StudentsGroup.students)
  return students_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::HW_7::Student >*
StudentsGroup::mutable_students() {
  // @@protoc_insertion_point(field_mutable_list:HW_7.StudentsGroup.students)
  return &students_;
}
inline const ::HW_7::Student& StudentsGroup::_internal_students(int index) const {
  return students_.Get(index);
}
inline const ::HW_7::Student& StudentsGroup::students(int index) const {
  // @@protoc_insertion_point(field_get:HW_7.StudentsGroup.students)
  return _internal_students(index);
}
inline ::HW_7::Student* StudentsGroup::_internal_add_students() {
  return students_.Add();
}
inline ::HW_7::Student* StudentsGroup::add_students() {
  // @@protoc_insertion_point(field_add:HW_7.StudentsGroup.students)
  return _internal_add_students();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::HW_7::Student >&
StudentsGroup::students() const {
  // @@protoc_insertion_point(field_list:HW_7.StudentsGroup.students)
  return students_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace HW_7

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Source_2eproto
