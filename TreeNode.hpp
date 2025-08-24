#ifndef __TREENODE_
#define __TREENODE_

#include <String.hpp>
#include <List.hpp>


// Generic n-ary tree nodes
template <typename DataType>
class TreeNode
{
    protected:
        String name = "Unnamed";
        DataType* data = nullptr;

        TreeNode<DataType>* parent = nullptr;
        int level = 0;
        List <TreeNode<DataType>*> children;
        List < List<TreeNode<DataType>*> > nodesByLevel;

    public:
        // Create an unnamed and empty node (without any data)
        TreeNode ()
        {
            
        }


        // Creates an empty node (without any data) wit the given name
        TreeNode (String name)
        {
            SetName (name);
        }


        // Creates an unnamed node with the given data
        TreeNode (DataType* data)
        {
            SetData (data);
        }


        // Creates a node with the given name and data
        TreeNode (String name, DataType* data)
        {
            SetName (name);
            SetData (data);
        }


        // Delete this node and all its children
        ~TreeNode ()
        {
            DeleteChildren ();
            ClearData ();
            Detach ();
        }


        // /* TODO
        // Adds a new empty and unnamed child
        TreeNode<DataType>* AddNewNode ()
        {
            TreeNode<DataType>* newNode = new TreeNode<DataType>();
            newNode->AttachTo (this);
            return newNode;
        }


        // Adds a new empty child with the given name
        TreeNode<DataType>* AddNewNode (String name)
        {
            TreeNode<DataType>* newNode = new TreeNode<DataType> (name);
            newNode->AttachTo (this);
            return newNode;
        }


        // Adds a new unnamed child with the given data
        TreeNode<DataType>* AddNewNode (DataType* data)
        {
            TreeNode<DataType>* newNode = new TreeNode<DataType> (data);
            newNode->AttachTo (this);
            return newNode;
        }


        // Adds a new child with the given name and data
        TreeNode<DataType>* AddNewNode (String name, DataType* data)
        {
            TreeNode<DataType>* newNode = new TreeNode<DataType> (name, data);
            newNode->AttachTo (this);
            return newNode;
        }


        /*
        // This isn't needed i think...
        //
        // Adds the given node to this one children
        TreeNode<DataType>* AddNode (TreeNode<DataType>* node) 
        {
            return nullptr;
        }
        */


        // Attach this node to the given one
        TreeNode<DataType>* AttachTo (TreeNode<DataType>* node)
        {
            if (HasParent ())
            {
                Detach ();
            }

            node->children.push_back (this);
            this->parent = node;
            return node;
        }


        // Returns a child node given its index
        TreeNode<DataType>* Child (int index)
        {
            if (!HasChild (index))
            {
                return nullptr;
            }

            return children.at (index);
        }
        
        
        // Returns a child node given its name
        TreeNode<DataType>* Child (String name)
        {
            for (int c = 0; c < children.size(); c ++)
            {
                TreeNode<DataType>* c_child = children.at (c);
                
                if (c_child->Name() == name)
                {
                    return c_child;
                }
            }

            return nullptr;
        }
        
        
        // Returns how many children this node has
        int ChildCount ()
        {
            return children.size ();
        }


        // Returns the index of the given node
        int ChildIndex (TreeNode<DataType>* child)
        {
            for (int c = 0; c < children.size(); c ++)
            {
                if (children.at(c) == child)
                {
                    return c;
                }
            }

            return -1;
        }
        
        
        // Returns this node children
        List< TreeNode<DataType>* >& Children ()
        {
            return children;
        }


        // Deletes this node data
        void ClearData ()
        {
            if (data != nullptr)
            {
                delete data;
                data = nullptr;
            }
        }
        
        
        // Copies this node below another
        // This creates a copy of this node and attach to the given one
        void CopyTo (TreeNode<DataType>* node)
        {

        }
        
        
        // Copies this node below another with another name
        void CopyTo (TreeNode<DataType>* node, String newName)
        {

        }
        
        
        // Returns this node data (value)
        DataType& Data ()
        {
            return *data;
        }


        // Returns this node data (pointer)
        DataType* DataPtr ()
        {
            return data;
        }
        
        
        // Delete this node
        void Delete ()
        {
            this->Detach ();
            delete this;
        }
        
        
        // Delete the given child
        void DeleteChild (TreeNode<DataType>* child)
        {
            for (int i = 0; i < children.size(); i ++)
            {
                if (children[i] == child)
                {
                    DeleteChild (child);
                }
            }
        }
        
        
        // Delete a child node given its index
        void DeleteChild (int childIndex)
        {
            if (HasChild (childIndex))
            {
                children.erase (children.begin() + childIndex);
            }
        }


        // Delete this node children
        void DeleteChildren ()
        {
            for (TreeNode<DataType>* child : children)
            {
                delete child;
            }

            children.clear ();
        }
        
        
        // Detach this node.
        // This will both unlink it from its parent and remove
        // from the parent children list.
        TreeNode<DataType>* Detach ()
        {
            if (IsRoot ())
            {
                // This is the root node. Cannot be detached.
                return nullptr;
            }
 
            this->parent->removeChild (this);
            this->parent = nullptr;

            return this;
        };


        // Detach the given node
        // This will both unlink it from its parent and remove
        // from the parent children list.
        TreeNode<DataType>* DetachNode (TreeNode<DataType>* node)
        {
            if (node == nullptr)
            {
                return nullptr;
            }

            return node->Detach ();
        }


    private:
        // Returns the first node that matchs the given name
        // in the given tree
        TreeNode<DataType>* findNode (TreeNode<DataType>* fromNode, 
                                      const String& name)
        {
            if (fromNode->name == name)
            {
                return fromNode;
            }

            for (TreeNode<DataType>* child : fromNode->children)
            {
                TreeNode<DataType>* foundNode = findNode (child, name);

                if (foundNode != nullptr)
                {
                    return foundNode;
                }
            }

            return nullptr;
        }


        // Returns all the nodes wit the given name
        // in the given tree
        List<TreeNode<DataType>*> findNodes (TreeNode<DataType>* fromNode,
                                             const String& name)
        {
            List<TreeNode<DataType>*> foundNodes;

            if (fromNode->name == name)
            {
                foundNodes.push_back (fromNode);
            }

            for (TreeNode<DataType>* child : fromNode->children)
            {
                List<TreeNode<DataType>*> foundChildren = 
                    findNodes (child, name);
                
                foundNodes.insert (foundNodes.end (), 
                                   foundChildren.begin (), 
                                   foundChildren.end ());
            }

            return foundNodes;
        }


    public:
        // Returns the first node that matchs the given name
        // in the current tree
        TreeNode<DataType>* FindNode (String nodeName)
        {
            return findNode (this, nodeName);
        }


        // Returns all existing nodes with the given name in the
        // current tree
        List<TreeNode<DataType>*> FindNodes (String nodeName)
        {
            return findNodes (this, nodeName);
        }


        // Executes a function for each node of the current tree,
        // including this one
        void ForEachNode (void (*func) (TreeNode<DataType>*))
        {
            ForEachNode (this, func);
        }


        // Executes a function for each of the given node tree,
        // including itself
        void ForEachNode (TreeNode<DataType>* node, 
                          void (*func) (TreeNode<DataType>*))
        {
            if (node == nullptr)
            {
                return;
            }

            func (node);

            for (TreeNode<DataType>* child : node->children)
            {
                ForEachNode (child, func);
            }
        }


        // Returns if this node has a child in the given index
        bool HasChild (int childIndex)
        {
            return ((childIndex >= 0) && (childIndex < ChildCount()));
        }


        // Returns if this node has parent
        bool HasParent ()
        {
            return !IsRoot ();
        }


        // Returns if this node is the root one
        bool IsRoot ()
        {
            return (parent == nullptr);
        }


        // Returns this child level.
        // Root is level 0, and every child beneath it 1, 2, 3...
        int Level ()
        {
            return level;
        }


        // Moves this node to another node.
        // Detachs from the actual parent and attach to the new one.
        bool MoveTo (TreeNode<DataType>* newParent)
        {
            if (newParent == nullptr)
            {
                return false;
            }
            
            this->Detach ();
            this->AttachTo (newParent);

            return true;
        }


        // Returns this node name
        String Name ()
        {
            return name;
        }


        // Returns all nodes located at the given level or depth.
        // Level 0 has always one node, the root.
        List< TreeNode<DataType> > NodesInLevel (int level)
        {
            if ((level >= 1) && (level < nodesByLevel.size()))
            {
                return nodesByLevel.at(level);
            }
        }


        // Returns this node parent
        TreeNode<DataType>* Parent ()
        {
            return parent;
        }

    
    private:
        // Removes a node from this node children list but NOT DELETES IT 
        bool removeChild (TreeNode<DataType>* child)
        {
            int childIndex = ChildIndex (child);

            if (childIndex == -1)
            {
                return false;
            }

            children.erase (children.begin() + childIndex);
            return true;
        }


    public:
        // Returns this node root
        TreeNode<DataType>* Root ()
        {
            if (parent == nullptr)
            {
                return this;
            }
            else
            {
                return parent->Root ();
            }
        }


        // Sets this node data
        void SetData (DataType* data)
        {
            this->data = data;
        }


        // Returns a list with all siblings of this node
        List< TreeNode<DataType>* > Siblings ()
        {
            List< TreeNode<DataType>* > siblings;

            for (TreeNode<DataType>* child : parent->children)
            {
                if (child == this)
                {
                    continue;
                }

                siblings.push_back (child);
            }

            return siblings;
        }


        // Renames this node
        void SetName (String name)
        {
            this->name = name;
        }
        

        // Weight this tree
        void Weight ()
        {
            Weight (this);
        }


        // Weight the given tree
        void Weight (TreeNode<DataType>* node, int currentLevel = 0)
        {
            if (currentLevel == 0)
            {
                nodesByLevel.clear ();
            }

            if (node == nullptr)
            {
                return;
            }

            if ((currentLevel + 1) > nodesByLevel.size())
            {
                nodesByLevel.push_back ( List<TreeNode<DataType>*> () );
            }

            node->level = currentLevel;
            
            ((List< TreeNode<DataType>* >) nodesByLevel.at(
                currentLevel)
            ).push_back (this);

            for (TreeNode<DataType>* child : node->children)
            {
                Weight (child, (currentLevel +1));
            }
        }
};
#endif










