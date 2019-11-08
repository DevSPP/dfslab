#include "tree.h"

int main()
{
  DATA d1, d2, d3;
  d1.var1 = 10;
  d2.var1 = 30;
  d3.var1 = 40;
  BTREE *l;
  l = init_btree();
  insertEnd_bt(l, d1);
  insertEnd_bt(l, d2);
  print_bt(l);
  insertEnd_bt(l, d3);
  print_bt(l);
  d1.var1 = 15;
  d2.var1 = 25;
  d3.var1 = 45;
  insertEnd_bt(l, d1);
  insertEnd_bt(l, d2);
  print_bt(l);
  destroy_bt(l);
  l = NULL;
}
