template <typename T>
class Vector {
  private:
    T* data;        // Pointeur vers les données stockées dans le vecteur
    std::size_t size_;  // Nombre d'éléments dans le vecteur
    std::size_t capacity_;  // Taille maximale du vecteur avant redimensionnement

  public:
    Vector() : size_(0), capacity_(1) {
        data = new T[capacity_];
    }

    // Constructeur de copie
    Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
        data = new T[capacity_];
        std::copy(other.data, other.data + size_, data);
    }

    // Opérateur d'affectation
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data = new T[capacity_];
            std::copy(other.data, other.data + size_, data);
        }
        return *this;
    }

    // Destructeur
    ~Vector() {
        delete[] data;
    }

    // Accès en lecture/écriture à un élément du vecteur
    T& operator[](std::size_t index) {
        return data[index];
    }

    // Accès en lecture seule à un élément du vecteur
    const T& operator[](std::size_t index) const {
        return data[index];
    }

    // Ajout d'un élément à la fin du vecteur
    void push_back(const T& element) {
        if (size_ == capacity_) {
            // Redimensionnement du vecteur si nécessaire
            capacity_ *= 2;
            T* new_data = new T[capacity_];
            std::copy(data, data + size_, new_data);
            delete[] data;
            data = new_data;
        }
        data[size_] = element;
        ++size_;
    }

    // Retrait d'un élément à la fin du vecteur
    void pop_back() {
        --size_;
    }

    // Obtention de la taille actuelle du vecteur
    std::size_t size() const {
        return size_;
    }

    // Vérification de l'absence d'éléments dans le vecteur
    bool empty() const {
        return size_ == 0;
    }
};
