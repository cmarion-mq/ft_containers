template <typename T>
class Vector {
  public:
    Vector(): data_(nullptr), size_(0), capacity_(0) {}
    ~Vector() { delete[] data_; }

    void push_back(const T& element) {
      if (size_ == capacity_) {
        // On doit redimensionner le tableau
        T* new_data = new T[capacity_ * 2];
        for (int i = 0; i < size_; ++i) {
          new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ *= 2;
      }

      data_[size_] = element;
      ++size_;
    }

    T& operator[](int index) {
      return data_[index];
    }

    const T& operator[](int index) const {
      return data_[index];
    }

    int size() const { return size_; }

  private:
    T* data_;
    int size_;
    int capacity_;
};


/*Cette implémentation de Vector a une capacité de stockage initiale de 0 et double sa capacité chaque fois qu'un nouvel élément est ajouté au-delà de sa capacité actuelle. Cependant, cette implémentation a quelques limitations:

Elle ne supporte pas les opérations de suppression d'éléments, comme pop_back ou erase.
Elle ne supporte pas les opérations de recherche d'éléments, comme find ou count.
Elle ne supporte pas les opérations de tri, comme sort.
Elle ne supporte pas les itérateurs.
Pour une implémentation complète de std::vector, il faudrait inclure ces fonctionnalités et d'autres encore.*/