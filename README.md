# 📂 Making File Names Unique — LeetCode 1487

This repository contains the C++ solution for **LeetCode Problem 1487 — Making File Names Unique**.

---

# 🚀 Problem Statement

Given an array of strings `names`, the task is to create unique folder names.

If a folder name already exists, a suffix in the form of:

```cpp id="d1f2g3"
(k)
```

is added, where `k` is the smallest positive integer such that the new folder name becomes unique.

---

# 📌 Example

## Input

```cpp id="a4b5c6"
["gta","gta(1)","gta","avalon"]
```

## Output

```cpp id="h7i8j9"
["gta","gta(1)","gta(2)","avalon"]
```

---

# 🧠 Approach Used

For every folder name:

1. Check if the name already exists
2. If not:

   * Store it directly
3. If yes:

   * Append `(k)` with the smallest possible integer
   * Keep increasing `k` until a unique name is found
4. Store the final unique name

An `unordered_map` is used for fast lookup and duplicate handling.

---

# 💻 C++ Solution

```cpp id="k1l2m3"
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {

        unordered_map<string,int> mp;
        vector<string> ans;

        for(int i = 0; i < names.size(); i++)
        {
            string curr = names[i];

            // First occurrence
            if(mp.find(curr) == mp.end())
            {
                ans.push_back(curr);
                mp[curr] = 1;
            }
            else
            {
                int k = mp[curr];

                string temp = curr + "(" + to_string(k) + ")";

                // Find smallest unique name
                while(mp.find(temp) != mp.end())
                {
                    k++;
                    temp = curr + "(" + to_string(k) + ")";
                }

                ans.push_back(temp);

                // Update next available number
                mp[curr] = k + 1;

                // Mark generated name as used
                mp[temp] = 1;
            }
        }

        return ans;
    }
};
```

---

# ⚡ Time Complexity

* **Time Complexity:** `O(N)`
* **Space Complexity:** `O(N)`

Where:

* `N` = Number of folder names

---

# 🛠 Concepts Used

* Hash Map (`unordered_map`)
* String Manipulation
* Duplicate Handling
* Simulation
* Greedy Logic

---

# 🔥 Important Edge Case

```cpp id="n4o5p6"
["kaido","kaido(1)","kaido","kaido(1)"]
```

## Correct Output

```cpp id="q7r8s9"
["kaido","kaido(1)","kaido(2)","kaido(1)(1)"]
```

### Key Learning:

`"kaido(1)"` itself is already a valid independent folder name and should NOT be treated as `"kaido"` + `1`.

---

# 📚 What I Learned

✅ Importance of carefully reading problem statements
✅ Handling tricky edge cases
✅ Efficient use of Hash Maps for duplicate tracking
✅ Maintaining uniqueness with minimal suffix generation

---

# 📌 LeetCode Link

https://leetcode.com/problems/making-file-names-unique/

---

# 🌟 Connect With Me

💼 LinkedIn: https://www.linkedin.com/in/mohd-wasim-49b719292/

⭐ If you found this helpful, don't forget to star the repository!
