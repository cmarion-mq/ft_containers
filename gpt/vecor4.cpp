template <typename T>
class Vector {
private:
  T* data;
  size_t size;
  size_t capacity;

public:
  Vector() : data(nullptr), size(0), capacity(0) {}

  ~Vector() {
    delete[] data;
  }

  void push_back(const T& value) {
    if (size == capacity) {
      resize();
    }
    data[size++] = value;
  }

  void pop_back() {
    if (size > 0) {
      --size;
    }
  }

  T& operator[](size_t index) {
    return data[index];
  }

  const T& operator[](size_t index) const {
    return data[index];
  }

  size_t get_size() const {
    return size;
  }

  size_t get_capacity() const {
    return capacity;
  }

private:
  void resize() {
    if (capacity == 0) {
      capacity = 1;
    } else {
      capacity *= 2;
    }

    T* new_data = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
      new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
  }
};
 /*Cette implémentation de vecteur utilise un tableau dynamique pour stocker ses éléments et redimensionne ce tableau lorsque nécessaire pour s'assurer qu'il y a suffisamment de place pour les nouveaux éléments. Le vecteur possède également une fonction push_back pour ajouter un élément à la fin du vecteur, une fonction pop_back pour enlever le dernier élément et des opérateurs d'indexation pour accéder aux éléments du vecteur.

Il convient de noter que cette implémentation est très simplifiée et qu'elle manque de nombreuses fonctionnalités et optimisations que possède la version standard de std::vector.*/