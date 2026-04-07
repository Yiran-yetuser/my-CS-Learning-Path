class Robot {
private:
    int width, height;
    int count;
    bool isGo;

public:
    Robot(int w, int h) {
        width = w;
        height = h;
        count = 0;
        isGo = false;
    }

    void step(int num) {
        isGo = true;
        count += num;
        count %= (width + height - 2) * 2;
    }

    vector<int> getPos() {
        if (count < width) {
            return {count, 0};
        } else if (count < width + height - 1) {
            return {width - 1, count - width + 1};
        } else if (count < 2 * width + height - 2) {
            return {width * 2 + height - count - 3, height - 1};
        } else {
            return {0, (width + height) * 2 - count - 4};
        }
    }

    string getDir() {
        if (count < width) {
            if (count == 0 && isGo == true) {
                return "South";
            }
            return "East";
        } else if (count < width + height - 1) {
            return "North";
        } else if (count < 2 * width + height - 2) {
            return "West";
        } else {
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
