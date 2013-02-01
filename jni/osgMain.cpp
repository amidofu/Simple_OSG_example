#include "osgMain.h"



osgMain::osgMain()
{
}
void osgMain::draw()
{
	viewer->frame();
}
void osgMain::initOSG(int width, int height)
{
	root=new osg::Group();

	osg::ref_ptr<osg::Light> light=new osg::Light;
	light->setPosition(osg::Vec4(0.0,0.0,10000.0,1.0));
	osg::ref_ptr<osg::LightSource> lightsrc=new osg::LightSource;
	lightsrc->setLight(light);
	root->addChild(lightsrc);

	root->getOrCreateStateSet()->setMode(GL_LIGHT0,osg::StateAttribute::ON);
	mt=new osg::MatrixTransform;
	//let the model rotate around z-axis
	mt->setUpdateCallback(new TestCallback());
    osg::Vec4 yellow;
    yellow.set(1.0,1.0,0.0,1.0);
    mt->addChild(Triangle(yellow));
    root->addChild(mt);

	viewer = new osgViewer::Viewer();
	viewer->setUpViewerAsEmbeddedInWindow(0, 0, width, height);
	viewer->realize();

	//the same as the example
    state = root->getOrCreateStateSet();
    state->setMode(GL_LIGHTING, osg::StateAttribute::ON);
    state->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);
    state->setMode(GL_CULL_FACE, osg::StateAttribute::ON);


	viewer->setSceneData(root.get());

	viewer->home();
	//__android_log_write(ANDROID_LOG_DEBUG,"OK","OK");

	//set the camera position and direction
	viewer->getCamera()->setViewMatrixAsLookAt(osg::Vec3(0,-100,0),osg::Vec3(0,0,0),osg::Vec3(0,0,1));
	//set background color to be red
	viewer->getCamera()->setClearColor(osg::Vec4(1.0f,0.0f,0.0f,1.0f));
}
osgMain::~osgMain()
{
}

osg::ref_ptr<osg::Geode> Triangle(osg::Vec4 & color)
{
	osg::ref_ptr<osg::Geode> geode=new osg::Geode;


	    osg::ref_ptr<osg::Vec3Array> v=new osg::Vec3Array;

	    v->push_back(osg::Vec3(-10,0,-10));
	    v->push_back(osg::Vec3(10,0,-10));
	    v->push_back(osg::Vec3(0,0,50));



	    osg::ref_ptr<osg::Vec4Array> colors=new osg::Vec4Array;

	    colors->push_back(color);
	    colors->push_back(color);
	    colors->push_back(color);
	    colors->push_back(color);

	    //triangle drew by triangle strip for test
	    osg::ref_ptr<osg::Geometry> geometry2=new osg::Geometry();
	    geometry2->setVertexArray(v);
	    geometry2->setColorArray(colors);
	    geometry2->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	    osg::ref_ptr<osg::DrawArrays> array=new osg::DrawArrays(GL_TRIANGLES,0,3);
	    geometry2->addPrimitiveSet(array);
	    geode->addDrawable(geometry2);
	    geode->setDataVariance(osg::Object::STATIC);
	    osg::ref_ptr<osg::Material> mat=new osg::Material;
	    mat->setDiffuse(osg::Material::FRONT_AND_BACK,color);
	    geode->getOrCreateStateSet()->setAttributeAndModes(mat.get());
	    geode->getOrCreateStateSet()->setMode(GL_CULL_FACE,osg::StateAttribute::OFF);
	    return geode;
}
