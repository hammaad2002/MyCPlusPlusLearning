from scenariogeneration.scenariogeneration import ScenarioGenerator, xosc, xodr

class simple_Scenario(ScenarioGenerator):
    def __init__(self):
        super().__init__()
        self.open_scenario_version = 2
   
    def road(self):
         # create a road
         road = xodr.create_road([xodr.Line(1000)], 
                                id=0, 
                                left_lanes=2, 
                                right_lanes=2)

         ## Create the OpenDrive class (Master class)
         odr = xodr.OpenDrive("myroad")

         ## Finally add roads to Opendrive
         odr.add_road(road)

         # Adjust initial positions of the roads looking at succ-pred logic
         odr.adjust_roads_and_lanes()
         
         return odr

    def scenario(self):
        ### create catalogs
        catalog = xosc.Catalog()

        ### create road
        road = xosc.RoadNetwork(
            roadfile=(self.road_file))

        ### create vehicles

        bb = xosc.BoundingBox(2, 5, 1.8, 2.0, 0, 0.9)
        fa = xosc.Axle(0.523598775598, 0.8, 1.68, 2.98, 0.4)
        ba = xosc.Axle(0.523598775598, 0.8, 1.68, 0, 0.4)
        white_veh = xosc.Vehicle(
	    "car_white", xosc.VehicleCategory.car, bb, fa, ba, 69, 10, 10
	)

        bb = xosc.BoundingBox(1.8, 4.5, 1.5, 1.3, 0, 0.8)
        fa = xosc.Axle(0.523598775598, 0.8, 1.68, 2.98, 0.4)
        ba = xosc.Axle(0.523598775598, 0.8, 1.68, 0, 0.4)
        red_veh = xosc.Vehicle(
            "car_red", xosc.VehicleCategory.car, bb, fa, ba, 69, 10, 10
        )

        ## create entities

        egoname = "Ego"
        targetname = "Target"

        entities = xosc.Entities()
        entities.add_scenario_object(egoname, white_veh)
        entities.add_scenario_object(targetname, red_veh)

        ### create init

        init = xosc.Init()
        step_time = xosc.TransitionDynamics(
            xosc.DynamicsShapes.step, xosc.DynamicsDimension.time, 1
        )

        egospeed = xosc.AbsoluteSpeedAction(3, step_time)
        egostart = xosc.TeleportAction(xosc.LanePosition(25, 0, -3, 0))

        targetspeed = xosc.AbsoluteSpeedAction(15, step_time)
        targetstart = xosc.TeleportAction(xosc.RelativeRoadPosition(30, 0, egoname))

        init.add_init_action(egoname, egospeed)
        init.add_init_action(egoname, egostart)
        init.add_init_action(targetname, targetspeed)
        init.add_init_action(targetname, targetstart)

        ## create the storyboard
        sb = xosc.StoryBoard(
            init,
            xosc.ValueTrigger(
                "stop_simulation",
                0,
                xosc.ConditionEdge.rising,
                xosc.SimulationTimeCondition(15, xosc.Rule.greaterThan),
                "stop",
            ),
        )

        ## create the scenario
        sce = xosc.Scenario(
            "Simplest_scenario",
            "HammadAliKhan",
            xosc.ParameterDeclarations(),
            entities=entities,
            storyboard=sb,
            roadnetwork=road,
            catalog=catalog,
            osc_minor_version=self.open_scenario_version,
        )

        return sce

tempObject = simple_Scenario()
tempObject.generate("./temporaryScenario")
