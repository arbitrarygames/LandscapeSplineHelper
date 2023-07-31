# Landscape Spline Helper Plugin
An Unreal Engine 5.2 plugin that lets you access Unreal Engine landscape splines inside blueprint

## Getting Started
1. Download & extract the [plugin zip file](https://github.com/arbitrarygames/LandscapeSplineHelper/releases) into your game's Plugins folder.
2. In Unreal Engine, go to Plugins, and enable Landscape Spline Helper.
3. Restart unreal

## Using the plugin
1. Go to your blueprint where you want to get the landscape spline component. 
2. Right click and type "Get Landscape Spline".
3. Drag off the Landscape input, and promote to variable.
4. Now it's up to you to set your landscape variable. (Hint: if your blueprint is an actor placed in the world, you can turn on "Instance Editable" in your landscape variable, and set it to your world's in the actor details panel)
