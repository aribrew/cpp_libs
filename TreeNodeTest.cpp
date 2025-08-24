#include <TreeNode.hpp>


void printNode (TreeNode<String>* node)
{
    std::cout << "[" << node->Name() << "]: ";
    std::cout << "(Level " << node->Level() << ") ";
    std::cout << node->Data() << std::endl;
}


int main ()
{
    TreeNode<String> root ("Root", new String ("0"));

    root.AddNewNode ("0", new String ("1.0"));
    root.AddNewNode ("0", new String ("1.1"));

    root.Child(0)->AddNewNode ("1", new String ("2.0"));
    root.Child(0)->Child(0)->AddNewNode ("2", new String ("3.0"));

    root.Weight ();

    root.ForEachNode (printNode);

    return 0;
}
