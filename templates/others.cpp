void bubble_sort(vi &a) {
   int n = a.size();
   for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1 - i; j++)  {
         if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
      }
   }
}

int make_unique(vi &a) {
   auto ip = unique(all(a));
   int n_size = distance(a.begin(), ip);
   a.resize(n_size);
   return n_size;
}

