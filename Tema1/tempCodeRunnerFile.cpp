for(int j = 0; j < n; j++) 
//             v[j] = victor[j];

//         w.resize(n, 0);
//         start0 = high_resolution_clock::now();
//         MergeSort( 0, n - 1);
//         stop0 = high_resolution_clock::now();

//         duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

//         cout << "\033[1;35mMerge Sort    \033[0m/ \033[1;35m" << fixed << duration0 << setprecision(5) << "sec" << "\033[0m / ";
//         testSort() ? cout << "\033[1;32mSortat cu succes!" : cout << "\033[1;31mFail";
//         cout << "\033[0m" << endl;
        

// //A doua sortare: Shell Sort
//         for(int j = 0; j < n; j++) 
//             v[j] = victor[j];
        
//         start0 = high_resolution_clock::now();
//         ShellSort(n);
//         stop0 = high_resolution_clock::now();

//         duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

//         cout << "Shell Sort    / " << fixed << duration0 << setprecision(5) << "sec" << " / ";
//         testSort() ? cout << "\033[1;32mSortat cu succes!" : cout << "\033[1;31mFail";
//         cout << "\033[0m" << endl;
        

// //A treia sortare: Radix Sort
//         for(int j = 0; j < n; j++) 
//             v[j] = victor[j];

//          w.resize(n, 0);

//         start0 = high_resolution_clock::now();
//         RadixSort(n);
//         stop0 = high_resolution_clock::now();

//         duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

//         cout << "\033[1;35mRadix Sort    \033[0m/ \033[1;35m" << fixed << duration0 << setprecision(5) << "sec" << "\033[0m / ";
//         testSort() ? cout << "\033[1;32mSortat cu succes!" : cout << "\033[1;31mFail";
//         cout << "\033[0m" << endl;