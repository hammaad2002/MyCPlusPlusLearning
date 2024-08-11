#include "esminiLib.hpp"
#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    float timestep = 0.01f;
    SE_Init("/myGitWork/esmini_work/temporaryScenario/xosc/temporary0.xosc", 0, 0, 0, 0);
    int id_ego;
    const char* name = "Ego";
    double counter_time = 0.0;
    id_ego = SE_GetIdByName(name);
    std::vector<double> time_container;
    std::vector<double> ego_s_container;

    while (SE_GetSimulationTime() < 1.0){
	SE_ScenarioObjectState ego_state;
	SE_GetObjectState(id_ego, &ego_state);
	double s = std::round(ego_state.s*1000.0)/1000;
	printf("------------------------------------------------------------\n");
	printf("At time step: %f the value of s is : %f\n", counter_time, s);
	printf("------------------------------------------------------------\n");
	counter_time += timestep;
	SE_StepDT(timestep);
	time_container.push_back(counter_time - timestep);
	ego_s_container.push_back(s);
    }

    int index = 0;
    for (auto i: time_container){
	if (std::fabs(i - 0.8) < (timestep/10)){
	    break;
	}
	else{
	index+=1;
	}
    }
    printf("The time at index %i should be equal to 0.8 and the value is %f.\n", index, time_container[index]);
    printf("The state of ego at 0.8 second is %f.\n", ego_s_container[index]);
    SE_Close();
    return 0;
}
