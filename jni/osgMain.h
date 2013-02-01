#include <iostream>
#include <osg/GL>
#include <osg/GLExtensions>
#include <osg/Depth>
#include <osg/Program>
#include <osg/Shader>
#include <osg/Node>
#include <osg/Notify>
#include <osg/Group>
#include <osg/Geometry>
#include <osg/Vec4>
#include <osg/Material>
#include <osg/Geode>
//osgText
#include <osgText/Text>
//osgDB
#include <osgDB/DatabasePager>
#include <osgDB/Registry>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
//osg_viewer
#include <osgViewer/Viewer>
#include <osgViewer/Renderer>
#include <osgViewer/ViewerEventHandlers>
//osgGA
#include <osgGA/GUIEventAdapter>
#include <osgGA/MultiTouchTrackballManipulator>
#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>
#include <osgGA/SphericalManipulator>

#include <android/log.h>
#include "TestCallback.h"
#include <string>

//just copied from the OSG example
//Static plugins Macro
USE_OSGPLUGIN(ive)
USE_OSGPLUGIN(osg)
USE_OSGPLUGIN(osg2)
USE_OSGPLUGIN(terrain)
USE_OSGPLUGIN(rgb)
USE_OSGPLUGIN(OpenFlight)
USE_OSGPLUGIN(dds)
//Static DOTOSG
USE_DOTOSGWRAPPER_LIBRARY(osg)
USE_DOTOSGWRAPPER_LIBRARY(osgFX)
USE_DOTOSGWRAPPER_LIBRARY(osgParticle)
USE_DOTOSGWRAPPER_LIBRARY(osgTerrain)
USE_DOTOSGWRAPPER_LIBRARY(osgText)
USE_DOTOSGWRAPPER_LIBRARY(osgViewer)
USE_DOTOSGWRAPPER_LIBRARY(osgVolume)
//Static serializer
USE_SERIALIZER_WRAPPER_LIBRARY(osg)
USE_SERIALIZER_WRAPPER_LIBRARY(osgAnimation)
USE_SERIALIZER_WRAPPER_LIBRARY(osgFX)
USE_SERIALIZER_WRAPPER_LIBRARY(osgManipulator)
USE_SERIALIZER_WRAPPER_LIBRARY(osgParticle)
USE_SERIALIZER_WRAPPER_LIBRARY(osgTerrain)
USE_SERIALIZER_WRAPPER_LIBRARY(osgText)
USE_SERIALIZER_WRAPPER_LIBRARY(osgVolume)

//pretty much the same as the OSG example
class osgMain{
private:
    osg::ref_ptr<osgViewer::Viewer> viewer;
    osg::ref_ptr<osg::Group> root;
    osg::ref_ptr<osg::StateSet> state;
    osg::ref_ptr<osg::MatrixTransform> mt;

public:
    void draw();
    void initOSG(int width,int height);
    osgMain();
    ~osgMain();
};
osg::ref_ptr<osg::Geode> Triangle(osg::Vec4 & color);
void itoa(int val,std::string& buf,int base);
