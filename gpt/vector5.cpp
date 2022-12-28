template <typename T>
class Vector {
 public:
  // Constructeurs
  Vector() : data_(nullptr), size_(0), capacity_(0) {}
  Vector(size_t n) : data_(new T[n]), size_(n), capacity_(n) {}
  Vector(size_t n, const T& val) : data_(new T[n]), size_(n), capacity_(n) {
    for (size_t i = 0; i < n; ++i) {
      data_[i] = val;
    }
  }
  Vector(const Vector& other) : data_(new T[other.size_]), size_(other.size_), capacity_(other.size_) {
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }
  Vector(Vector&& other) : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }
  ~Vector() { delete[] data_; }

  // Opérateurs d'affectation
  Vector& operator=(const Vector& other) {
    if (this != &other) {
      delete[] data_;
      data_ = new T[other.size_];
      size_ = other.size_;
      capacity_ = other.size_;
      for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
      }
    }
    return *this;
  }
  Vector& operator=(Vector&& other) {
    if (this != &other) {
      delete[] data_;
      data_ = other.data_;
      size_ = other.size_;
      capacity_ = other.capacity_;
      other.data_ = nullptr;
      other.size_ = 0;
      other.capacity_ = 0;
    }
    return *this;
  }

  // Accès en lecture/écriture
  T& operator[](size_t i) { return data_[i]; }
  const T& operator[](size_t i) const { return data_[i]; }
  T& front() { return data_[0]; }
  const T& front() const { return data_[0]; }
  T& back() { return data_[size_ - 1]; }
  const T& back() const { return data_[size_ - 1]; }

  // Itérateurs
  T* begin() { return data_; }
  const T* begin() const { return data_; }
  T* end() { return data_ + size_; }
  const T* end() const { return data_ + size_; }

  // Modification de la taille
  void resize(size_t n) {
    if (n > capacity_) {
      reserve(n);
    }
    size_ = n;
 
