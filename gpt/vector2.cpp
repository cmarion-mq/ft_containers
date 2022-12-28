template <typename T>
class Vector {
 public:
  // Constructeur par défaut
  Vector() : data_(nullptr), size_(0), capacity_(0) {}

  // Constructeur qui prend en paramètre la taille du vecteur et un éventuel élément par défaut
  Vector(size_t size, const T& default_value = T()) : data_(new T[size]), size_(size), capacity_(size) {
    std::fill(data_, data_ + size, default_value);
  }

  // Constructeur de copie
  Vector(const Vector& other) : data_(new T[other.size_]), size_(other.size_), capacity_(other.capacity_) {
    std::copy(other.data_, other.data_ + other.size_, data_);
  }

  // Opérateur d'affectation
  Vector& operator=(const Vector& other) {
    if (this != &other) {
      delete[] data_;
      data_ = new T[other.size_];
      size_ = other.size_;
      capacity_ = other.capacity_;
      std::copy(other.data_, other.data_ + other.size_, data_);
    }
    return *this;
  }

  // Destructeur
  ~Vector() {
    delete[] data_;
  }

  // Accesseur pour obtenir la taille du vecteur
  size_t size() const {
    return size_;
  }

  // Accesseur pour obtenir la capacité du vecteur
  size_t capacity() const {
    return capacity_;
  }

  // Fonction pour redimensionner le vecteur
  void resize(size_t new_size, const T& default_value = T()) {
    if (new_size > capacity_) {
      reserve(new_size);
    }
    if (new_size > size_) {
      std::fill(data_ + size_, data_ + new_size, default_value);
    }
    size_ = new_size;
  }

  // Fonction pour réserver de l'espace mémoire pour le vecteur
  void reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
      T* new_data = new T[new_capacity];
      std::copy(data_, data_ + size_, new_data);
      delete[] data_;
      data_ = new_data;
      capacity_ = new_capacity;
    }
  }

  // Opérateur d'indexation
  T& operator[](size_t index) {
    return data_[index];
  }

  // Opérateur de flux de sortie
  friend std::ostream& operator<<(std::ostream& out, const Vector& vec) {
    out << "[";
    for (size_t i = 0; i < vec.size_; ++i) {
      out << vec.data_[i];
      if (i
