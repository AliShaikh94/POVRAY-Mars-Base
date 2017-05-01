//Fire Jet - For the Walker
// #include "colors.inc"

// POV-Ray include file "Column_1.inc"
//-------------------------------------
#ifndef( FlameThrowerFire)
#declare FlameThrowerFire = version;
#version 3.7;
//-------------------------------------
#macro F_T_Fire ()
// plane {y,-2 pigment {NewTan} finish {ambient 0}}
// background {color Red}
// cylinder {0,z*-2,0.3 pigment{Gray} rotate -x*30}

#declare DensMap = density {
radial  rotate y*90 translate z*-5
translate <0,0,-15*clock>
warp {turbulence 0.8 octaves 3 lambda 2.5}
translate <0,0,15*clock>
scale <1,1,1> 
colour_map {
  [0.49 rgb 0]
  [0.495 rgb 1]
  [0.5 rgb 4]
  [0.505 rgb 1]
  [0.51 rgb 0]
}
}
#declare ColMap = density {
radial rotate y*90 translate z*-5
translate <0,0,-15*clock>
warp {turbulence 1.2 octaves 3 lambda 2.5}
translate <0,0,15*clock>
scale <1,1,1> 
colour_map {
  [0.495 Yellow]
  [0.5 White]
  [0.505 Yellow]
}
}
#declare DensEnding = density {
spherical scale 10
colour_map {
  [0 rgb 0*<1,0,0>]
  [0.5 rgb <1,.5,0>*.5]
  [.75 rgb <1,1,0>] 
  // [.875 rgb 1] 
  [1 rgb 1] 
  // [1 rgb <-1,0,1>]
}
}

#declare DensMap2 = density {
radial rotate y*90 translate z*-3
translate <0,0,-25*clock>
warp {turbulence 1.3 octaves 3 }
translate <0,0,25*clock>
scale <1,1,1>
colour_map {
  [0.45 rgb 0]
  [0.48 rgb 0.4]
  [0.5 rgb 1]
  [0.52 rgb 0.4]
  [0.55 rgb 0]
}
}
#declare ColMap2 = density {
radial rotate y*90 translate z*-3
translate <0,0,-25*clock>
warp {turbulence 1.3 octaves 3 }
translate <0,0,25*clock>
scale <1,1,1>
colour_map {
  [0.47 Red]
  [0.5 Orange]
  [0.53 Red]
}
}
#declare DensEnding2 = density {
spherical scale <5,5,10>
translate <0,0,-15*clock>
warp {turbulence 0.5}
translate <0,0,15*clock>
colour_map {
  [0 rgb 0]
  [0.1 rgb 1]
  [.875 rgb 1] 
  [1 rgb <-1,-1,1>]
}
}

#declare Flame =
union {
  cylinder {
    0,z*5,3

    pigment {Clear}
    hollow
    interior {
      media {
        emission 1
                        /*intervals 5
                        samples 2, 30
                        confidence 0.9999
                        variance 1/1000*/
        density {ColMap}
        density {DensMap}
        density {DensMap rotate z*90}
        density {DensEnding}
        scale 2
      }
      media {
        emission 1
                        /*intervals 5
                        samples 2, 30
                        confidence 0.9999
                        variance 1/1000*/
        density {ColMap2}
        density {DensMap2}
        density {DensMap2 rotate z*90}
        density {DensEnding2}
        scale 2
      }

    }
    scale <1,1,3>
  }

  // cylinder {
  //   0,z*10,3

  //   pigment {Clear}
  //   hollow
  //   interior {
  //     media {
  //       absorption rgb .675
  //                       //scattering { 2, rgb .5 extinction 1 }                        
  //       density {bozo
  //         translate <0,0,-5*clock>
  //         warp {turbulence 0.2 octaves 1 lambda .5}
  //         translate <0,0,5*clock> 
  //         scale <1,1,1/3>*.75                        
  //         color_map {
  //           [0 rgb 0]
  //           [1 rgb 1]         
  //         }
  //       }
  //       density {
  //         spherical scale <5,5,10>
  //         translate <0,0,-5*clock>
  //         warp {turbulence 0.5}
  //         translate <0,0,5*clock>
  //         color_map {
  //           [0 rgb 0]
  //           [1 rgb 1]         
  //         }
  //       }
  //       scale .8
  //     }
  //   }
  //   scale <.675,.675,2>/.8
  //   rotate -x*10
  //   translate <0,0,20>
  // }
  light_source { <0,0,0>          
   color rgb <0.8, 0.5, 0.2>*1   
               area_light            // kind of light source (Art der Lichtquelle)
               <0, 0, 0> <0, 0.25, 0> // lights spread out across this distance 
               1, 10                // total number of lights in grid  
               adaptive 3          // 0,1,2,3...
               jitter              // adds random softening of light
               translate<0,0,0>
             } //---------------- end of area_light 
}


// background {rgb .125}

// difference { 
// intersection{
object{Flame
      rotate x*90}
// cylinder {0,z*5,3 rotate x*90}

// }
#end
#version FlameThrowerFire;
#end 
// #declare numLights=5;
// union {
//         #declare i=0;
//         #while (i<10)
//                 #declare i = i + 10/numLights;
//   light_source {
//     z*i
//     color Red*1.9/numLights
//     media_interaction off
//     fade_distance 5 fade_power 0.8
//   }
//   light_source {
//     z*i
//     color Green*1.5/numLights
//     media_interaction off
//     fade_distance 5.5 fade_power 4
//   }
//         #end        
//   rotate -x*30
// }
