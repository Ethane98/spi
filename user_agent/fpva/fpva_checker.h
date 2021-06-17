#ifndef _FPVACHECKER_H_
#define _FPVACHECKER_H_

#include "SpInc.h"
#include "fpva_utils.h"
#include "trace_mgr.h"

namespace fpva {
//-----------------------------------------
// Base classes
//-----------------------------------------
class OneTimeChecker {
 public:
  OneTimeChecker(TraceMgr* mgr);
  virtual bool Run() = 0;
  virtual ~OneTimeChecker() {}

 protected:
  TraceMgr* mgr_;
};

class FpvaChecker {
 public:
  FpvaChecker(TraceMgr* mgr);
  virtual ~FpvaChecker() {}
  virtual bool PreCheck(sp::SpPoint* pt, sp::SpFunction* callee) = 0;
  virtual bool PostCheck(sp::PointHandle* pHandle) = 0;

 protected:
  TraceMgr* mgr_;
};

//-----------------------------------------
// Derived classes
//-----------------------------------------

// Check process stat
class ProcInitChecker : public OneTimeChecker {
 public:
  using OneTimeChecker::OneTimeChecker;
  virtual bool Run();
  ~ProcInitChecker() {}
};

// IPC
class IpcChecker : public FpvaChecker {
 public:
  using FpvaChecker::FpvaChecker;
  virtual ~IpcChecker() {}
  virtual bool PreCheck(sp::SpPoint* pt, sp::SpFunction* callee);
  virtual bool PostCheck(sp::PointHandle* pHandle);

 protected:
  string port;
};

class ForkChecker : public FpvaChecker {
 public:
  using FpvaChecker::FpvaChecker;
  virtual bool PreCheck(sp::SpPoint* pt, sp::SpFunction* callee);
  virtual bool PostCheck(sp::PointHandle* pHandle);
};

}  // namespace fpva
#endif /* _FPVACHECKER_H_ */
