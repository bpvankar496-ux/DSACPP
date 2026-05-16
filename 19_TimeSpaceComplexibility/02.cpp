//==> Quadratic Loop
// for(int i=0; i<n; i+K) {
//     for(int j=0; j<=K; j++) {
//         //constant work
//     }
// }
// Outer loop: i har vaar K vadhse, 0 thi n sudhi → n/K vaar chaale
// Inner loop: j 0 thi K sudhi → K+1 ≈ K vaar chaale
// Total = (n/K) × K = n
// Big O = O(n) — Linear! (K cancel thay jase)


// ==>Tricky Loop (i+K)
// for(int i=0; i<n; i+K) {
//     for(int j=0; j<=K; j++) {
//         //constant work
//     }
// }
// Outer loop: i har vaar K vadhse, 0 thi n sudhi → n/K vaar chaale
// Inner loop: j 0 thi K sudhi → K+1 ≈ K vaar chaale
// Total = (n/K) × K = n
// Big O = O(n) — Linear! (K cancel thay jase)



// ==>Nested Loop (j=i+1)
// for(int i=0; i<n; i++) {
//     for(int j=i+1; j<n; j++) {
//         //constant work ≤ K
//     }
// }
// Outer loop: i = 0 thi n-1
// Inner loop: j = i+1 thi n-1 (j always i thi aage thi sharu)
// i=0 → n-1 kaam, i=1 → n-2 kaam... ema ghate
// Total = (n-1)+(n-2)+...+1 = n(n-1)/2
// Big O = O(n²) — still Quadratic
// Note: ≤ K means inner loop K thi vadhu nai — O(n×K) but if K constant hoy to O(n)



// ==>Bubble Sort
// void bubbleSort(int arr[], int n) {
//     for(int i=0; i<n-1; i++) {
//         for(int j=0; j<n-i-1; j++) {
//             if(arr[j] > arr[j+1]) {
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }
// }
// i = pass number (0 thi n-2) → n-1 passes
// j = comparison kare adjacent elements → n-i-1 sudhi jase (har pass ma ek element sorted thay jase)
// arr[j] > arr[j+1] → jyare pehlo moto hoy to swap karo
// Har pass ma sabse moto element end ma jato rahe
// Total comparisons = (n-1)+(n-2)+...+1 = O(n²)
// Example: [5, 3, 8, 1]
// Pass 1: Compare 5-3 → swap → [3,5,8,1], 5-8 → ok, 8-1 → swap → [3,5,1,8]
// Pass 2: [3,1,5,8]
// Pass 3: [1,3,5,8] 



// ==>Binary Search
// int binSearch(int *arr, int n, int key) {
//     int start = 0, end = n-1;
//     while(start <= end) {
//         int mid = (start + end) / 2;
//         if(key == arr[mid]) {
//             return mid;         // found!
//         } else if(key > arr[mid]) {
//             start = mid + 1;    // 2nd half ma search
//         } else {
//             end = mid - 1;      // 1st half ma search
//         }
//     }
//     return -1;  // not found
// }
// start=0, end=n-1 → pura array thi sharu
// mid = (start+end)/2 → vacha no element levo
// Jyare key == arr[mid] → mli gayu! index return karo
// Jyare key > arr[mid] → key right side ma hase → start = mid+1 (left half badh)
// Jyare key < arr[mid] → key left side ma hase → end = mid-1 (right half badh)
// Har step ma array half thay jase
// Big O = O(log n) — Logarithmic!
// Example: [1,3,5,8,10], key=8
// mid=5, 8>5 → start=mid+1 → [8,10]
// mid=8, 8==8 → found at index 3! 



// ==>Merge Function
// void merge(int arr[], int si, int mid, int ei) {
//     vector<int> temp;
//     int i=si, j=mid+1;
//     while(i <= mid && j <= ei) {
//         if(arr[i] <= arr[j]) {
//             temp.push_back(arr[i++]);
//         } else {
//             temp.push_back(arr[j++]);
//         }
//     }
//     while(i <= mid) { temp.push_back(arr[i++]); }
//     while(j <= ei)  { temp.push_back(arr[j++]); }

//     for(int idx=si, x=0; idx<=ei; idx++) {
//         arr[idx] = temp[x++];
//     }
// }
// temp = temporary vector — sorted elements store karva
// i=si → left half no start, j=mid+1 → right half no start
// First while: banne half compare karo, nano element temp ma nako
// arr[i] <= arr[j] → left element nano/barabar → left levo, i++
// Otherwise → right element nano → right levo, j++
// Second while: left half na bache gaya elements direct nako
// Third while: right half na bache gaya elements direct nako
// Final for loop: temp thi wapas original array ma copy karo
// Time Complexity = O(n) for merging
// Example: Left: [1,5,8], Right: [2,4,9]
// Compare 1 vs 2 → 1 nako → temp: [1]
// Compare 5 vs 2 → 2 nako → temp: [1,2]
// Compare 5 vs 4 → 4 nako → temp: [1,2,4]
// Compare 5 vs 9 → 5 nako → temp: [1,2,4,5]
// Compare 8 vs 9 → 8 nako → temp: [1,2,4,5,8]
// 9 bache → temp: [1,2,4,5,8,9] 