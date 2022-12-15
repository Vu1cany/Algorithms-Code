struct PriorityQueue {
private:
    void SiftUp(int i) {
        while ((i - 1) / 2 >= 0 && vector1[(i - 1) / 2] > vector1[i]) {
            std::swap(vector1[(i - 1) / 2], vector1[i]);
            i = (i - 1) / 2;
        }
    }

    void SiftDown(int i) {
        int size = vector1.size();
        int root = i;

        while (2*i + 1 < size) {
            int left_child = 2*i + 1;
            int right_child = 2*i + 2;

            if (vector1[root] > vector1[left_child]) {
                root = left_child;
            }
            if (vector1[root] > vector1[right_child] && right_child < size) {
                root = right_child;
            }

            if (vector1[root] < vector1[i]) {
                std::swap(vector1[root], vector1[i]);
            } else break;
            i = root;
        }
    }

    std::vector<int> vector1;

public:
    void DecreaseKey(int key, int new_key) {
        int index = 0;
        for (int i = 0; i < vector1.size(); ++i) {
            if (vector1[i] == key) {
                vector1[i] = new_key;
                index = i;
                break;
            }
        }
        SiftUp(index);
    }

    void Push(int x) {
        vector1.push_back(x);
        SiftUp(vector1.size() - 1);
    }

    void ExtractMin() {
        int size = vector1.size();
        if (vector1.empty()) {
            std::cout << "*" << "\n";       //Если такого такого элемента нет ничего не удаляем
            return;
        }
        std::cout << vector1[0] << "\n";
        std::swap(vector1[0],vector1[size - 1]);
        vector1.pop_back();
        SiftDown(0);
    }
};