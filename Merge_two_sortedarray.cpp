vector<int> sortedArray(vector<int> a, vector<int> b) {
    int index_one = 0;
    int index_two = 0;
    vector<int> temp;

    while (index_one < a.size() && index_two < b.size()) {
        if (a[index_one] < b[index_two]) {
            if (temp.empty() || a[index_one] != temp.back()) {
                temp.push_back(a[index_one]);
            }
            index_one++;
        } else if (a[index_one] > b[index_two]) {
            if (temp.empty() || b[index_two] != temp.back()) {
                temp.push_back(b[index_two]);
            }
            index_two++;
        } else {
            if (temp.empty() || a[index_one] != temp.back()) {
                temp.push_back(a[index_one]);
            }
            index_one++;
            index_two++;
        }
    }

    // Append any remaining unique elements from a and b
    while (index_one < a.size()) {
        if (temp.empty() || a[index_one] != temp.back()) {
            temp.push_back(a[index_one]);
        }
        index_one++;
    }

    while (index_two < b.size()) {
        if (temp.empty() || b[index_two] != temp.back()) {
            temp.push_back(b[index_two]);
        }
        index_two++;
    }

    return temp;
}
