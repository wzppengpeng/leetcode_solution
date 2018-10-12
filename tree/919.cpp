/**
 * A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
CBTInserter.get_root() will return the head node of the tree
 */


/**
 * BFS，使用队列来保存数据结构，队列头始终是目前需要插入的节点指针
 */

class CBTInserter {
public:
    CBTInserter(TreeNode* root) : root_(root) {
        if(root_) {
            que_.push(root);
            while(!que_.empty()) {
                if(que_.front()->left) que_.push(que_.front()->left);
                if(que_.front()->right) que_.push(que_.front()->right);
                if(que_.front()->left && que_.front()->right) {
                    que_.pop();
                } else {
                    break;
                }
            }
        }
    }

    int insert(int v) {
        auto pre_v = que_.front()->val;
        auto* new_node = new TreeNode(v);
        if(!que_.front()->left) {
            que_.front()->left = new_node;
        } else {
            que_.front()->right = new_node;
            que_.pop();
        }
        que_.push(new_node);
        return pre_v;
    }

    TreeNode* get_root() {
        return root_;
    }

private:
    TreeNode* root_;
    std::queue<TreeNode*> que_;
};