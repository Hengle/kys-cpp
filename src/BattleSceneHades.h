#pragma once
#include "Scene.h"
#include "BattleMap.h"
#include "Save.h"

class BattleSceneHades : public Scene
{
public:
    BattleSceneHades();
    BattleSceneHades(int id);
    virtual ~BattleSceneHades();
    void setID(int id);

    //�̳��Ի���ĺ���
    virtual void draw() override;
    virtual void dealEvent(BP_Event& e) override;     //ս����ѭ��
    virtual void dealEvent2(BP_Event& e) override;    //����ֹͣ�Զ�
    virtual void onEntrance() override;
    virtual void onExit() override;
    virtual void backRun() override;

protected:
    int battle_id_ = 0;
    BattleInfo* info_;

    Save* save_;

    std::vector<Role*> battle_roles_;    //���в�ս��ɫ

    //����㣬�����㣬ѡ��㣨��ֵΪ����ѡ��0����ֵΪ��ѡ����Ч����
    MapSquareInt earth_layer_, building_layer_, select_layer_, effect_layer_;
};

