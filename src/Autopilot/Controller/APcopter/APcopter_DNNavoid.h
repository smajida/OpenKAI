
#ifndef OPENKAI_SRC_AUTOPILOT_ACTION_APCOPTER_DNNAVOID_H_
#define OPENKAI_SRC_AUTOPILOT_ACTION_APCOPTER_DNNAVOID_H_

#include "../../../Base/common.h"
#include "../../../DNN/Detector/_ImageNet.h"
#include "../../ActionBase.h"
#include "APcopter_base.h"

#define N_TERRAIN 16
#define N_TERRAIN_CLASS 8
#define N_TERRAIN_ACTION 8

namespace kai
{

struct TERRAIN_ACTION
{
	string m_pClass[N_TERRAIN_CLASS];
	uint8_t m_action;
};

struct TERRAIN
{
	uint8_t m_orientation;
	OBJECT* m_pObj;
	TERRAIN_ACTION m_action[N_TERRAIN_ACTION];
	int	m_nAction;

	void init(void)
	{
		m_orientation = 0;
		m_pObj = NULL;
	}
};

class APcopter_DNNavoid: public ActionBase
{
public:
	APcopter_DNNavoid();
	~APcopter_DNNavoid();

	bool init(void* pKiss);
	bool link(void);
	void update(void);
	bool draw(void);

private:
	APcopter_base* m_pAP;
	_ImageNet*	m_pIN;

	TERRAIN m_pTerrain[N_TERRAIN];
	int m_nTerrain;

};

}

#endif

