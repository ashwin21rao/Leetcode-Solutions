class FileSystem {
public:
    // each Node represents a file/directory in the filesystem
    class Node {
    public:
        unordered_map<string, Node*> children;
        bool isFile = false;
        string content = "";
        
        // search for path in filesystem
        // returns pointer to node and its name
        pair<Node*, string> search(string &path) {
            Node *node = this;
            int n = path.size();
            string name = "";
            
            for (int i=1; i<n; i++) {
                // extract name of directory/file
                int idx = path.find('/', i);
                name = path.substr(i, idx - i);
                i = idx;
                
                // if path doesnt exist
                if (node->children.find(name) == node->children.end())
                    return {nullptr, ""};
                
                node = node->children[name];
                
                if (i == string::npos)
                    break;
            }
            
            return {node, name};
        }
        
        // inserts path into filesystem
        void insert(string &path, bool isFile=false, string content="") {
            Node *node = this;
            int n = path.size();
            
            for (int i=1; i<n; i++) {
                // extract name of directory/file
                int idx = path.find('/', i);
                string name = path.substr(i, idx - i);
                i = idx;
                
                // create child if it doesnt exist
                if (node->children.find(name) == node->children.end())
                    node->children[name] = new Node();
                
                node = node->children[name];
                
                if (i == string::npos)
                    break;
            }
            
            // if new path is a file
            if (isFile) {
                node->isFile = true;
                node->content += content;
            }
        }
    };
    
    // root of file system
    Node *root = new Node();
    
    FileSystem() {
        
    }
    
    vector<string> ls(string path) {
        auto [node, name] = root->search(path);
        
        // path is a file
        if (node->isFile)
            return {name};

        // path is a directory
        vector<string> children;
        for (auto &[c_name, c_node] : node->children)
            children.push_back(c_name);
        
        sort(children.begin(), children.end());
        return children;
    }
    
    void mkdir(string path) {        
        root->insert(path);
    }
    
    void addContentToFile(string filePath, string content) {
        root->insert(filePath, true, content);    
    }
    
    string readContentFromFile(string filePath) {
        auto [node, name] = root->search(filePath);
        return node->content;
    }
};

/*
there are 2 main operations:
    - inserting a new path into the filesystem.
    - searching for a PREFIX of an existing path.

we consider the filesystem to be a tree of nodes.
    - this tree is similar in structure and implementation to a trie (prefix tree).
    - each node represents a file or directory.
    - directories or files in a directory are children of that directory.

the structure of each node is as follows:
    - children (unordered map): name of child -> pointer to Node of that child
    - isFile (bool): whether the node represents a file or not
    - content (string): content (if file)

ls:
    - search for the given path.
    - list all its children (or it's name if it represents a file).
    - time complexity: O(n + ClogC) where C is the number of children.

mkdir:
    - insert path into the tree.
    - time complexity: O(n)

addContentToFile:
    - search for the given path.
    - if path does not exist, insert path into the tree.
    - else, append content to the corresponding node.
    - time complexity: O(n)

readContentFromFile:
    - search for the given path.
    - return its content.
    - time complexity: O(n)

space complexity: O(M) where M is the total number of files and directories in the file system.

https://leetcode.com/problems/design-in-memory-file-system/
*/