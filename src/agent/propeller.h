#ifndef SP_PROPEL_H_
#define SP_PROPEL_H_

#include "common/common.h"
#include "agent/payload.h"

namespace sp {

  typedef std::vector<Dyninst::PatchAPI::Point*> Points;
  
  class AGENT_EXPORT SpPropeller {
  public:
    typedef SHARED_PTR(SpPropeller) ptr;
    static ptr create();
    SpPropeller();
		virtual ~SpPropeller() {}

    bool go(ph::PatchFunction* func,
            PayloadFunc entry,
            PayloadFunc exit,
            ph::Point* pt = NULL);

  protected:
    virtual void next_points(ph::PatchFunction* func,
                             ph::PatchMgrPtr mgr,
                             Points& pts);
  };

}

#endif /* SP_PROPEL_H_ */