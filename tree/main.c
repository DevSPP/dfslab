#include "tree.h"

int main()
{
  DATA d1, d2, d3;
  d1.var1 = 10;
  d2.var1 = 30;
  d3.var1 = 40;
  BTNODE *root;
  root = addNode(&d1);
  root->left = addNode(&d2);
  root->right = addNode(&d3);
}
