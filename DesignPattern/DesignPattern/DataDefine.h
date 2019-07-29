#ifndef _DATA_DEFINE_H_
#define _DATA_DEFINE_H_

// ºê¶¨Òå
#define SafeDelete(p)  if (p != nullptr) { delete p; p = nullptr; }
#define SafeDeletes(p) if (p != nullptr) { delete [] p; p = nullptr; }
#define SafeCloseThread(p1, p2) if (p1 != nullptr) { p2 = false; p1->join(); delete p1; p1 = nullptr; }
#define SafeCloseHandle(p) if (p != nullptr) { CloseHandle(p); p = nullptr; }

#endif // _DATA_DEFINE_H_