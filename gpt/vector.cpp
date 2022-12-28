template <typename T>
class Vector {
private:
    T* data;  // pointeur vers le tableau de données
    size_t size;  // nombre d'éléments actuellement dans le vecteur
    size_t capacity;  // capacité actuelle du tableau de données

public:
    // Constructeur par défaut
    Vector() : data(nullptr), size(0), capacity(0) {}

    // Constructeur qui prend le nombre d'éléments en argument
    Vector(size_t count) : data(new T[count]), size(count), capacity(count) {}

    // Constructeur de copie
    Vector(const Vector<T>& other) : data(new T[other.size]), size(other.size), capacity(other.size) {
        std::copy(other.data, other.data + other.size, data);
    }

    // Opérateur d'affectation
    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {
            delete[] data;
            data = new T[other.size];
            size = other.size;
            capacity = other.size;
            std::copy(other.data, other.data + other.size, data);
        }
        return *this;
    }

    // Destructeur
    ~Vector() {
        delete[] data;
    }

    // Accesseur pour l'élément à l'index spécifié
    T& operator[](size_t index) {
        return data[index];
    }

    // Accesseur en lecture seule pour l'élément à l'index spécifié
    const T& operator[](size_t index) const {
        return data[index];
    }

    // Ajoute un élément à la fin du vecteur
    void push_back(const T& element) {
        if (size == capacity) {
            // Si le tableau de données est plein, on doit le redimensionner
            T* new_data = new T[capacity == 0 ? 1 : 2 * capacity];
            std::copy(data, data + size, new_data);
            delete[] data;
            data = new_data;
            capacity = capacity == 0 ? 1 : 2 * capacity;
        }
        data[size] = element;
        ++size;
    }

    // Retourne le nombre d'éléments dans le vecteur
    size_t size() const {
        return size;
    }
};
