/* { dg-do compile } */ 
/* { dg-options "-O2 -fdump-tree-pre-stats" } */
/* LLVM LOCAL test not applicable */
/* { dg-require-fdump "" } */
typedef int type[2];
int main(type *a, int argc)
{
  int d, e;
  
  /* Should be able to eliminate the second load of *a along the main path. */
  d = (*a)[argc];
  if (!d)
      argc++;
  e = (*a)[argc];
  return e;
}
/* { dg-final { scan-tree-dump-times "Eliminated: 1" 1 "pre"  } } */
/* { dg-final { cleanup-tree-dump "pre" } } */
