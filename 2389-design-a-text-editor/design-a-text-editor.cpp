    class TextEditor {
        // stack preferred here :(, linked list approach is more intresting
        std::vector<char> left;
        std::vector<char> right;
    public:
        TextEditor() { }
        
        void addText(string text) {
            for (auto c : text) left.push_back(c);
        }
        
        int deleteText(int k) {
            int count = 0;
            while(!left.empty() && k) {
                left.pop_back();
                --k;
                ++count;
            }
            return count;
        }
        
        string cursorLeft(int k) {
            while (!left.empty() && k) {
                right.push_back(left.back());
                left.pop_back();
                --k;
            }
                int len = min(10, (int)left.size());

        return string(left.end() - len, left.end());;
        }
        
        string cursorRight(int k) {
            while(!right.empty() && k) {
                left.push_back(right.back());
                right.pop_back();
                --k;
            }
            int len = min(10, (int)left.size());
            return string(left.end() - len, left.end());;
        }
    };

    /**
    * Your TextEditor object will be instantiated and called as such:
    * TextEditor* obj = new TextEditor();
    * obj->addText(text);
    * int param_2 = obj->deleteText(k);
    * string param_3 = obj->cursorLeft(k);
    * string param_4 = obj->cursorRight(k);
    */
