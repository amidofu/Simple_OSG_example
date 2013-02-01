#include "TestCallback.h"

TestCallback::TestCallback()
{
	angle=0.0;
}
void TestCallback::operator()(osg::Node* node,osg::NodeVisitor* nv)
{
	osg::ref_ptr<osg::MatrixTransform> mt=dynamic_cast<osg::MatrixTransform*>(node);

	osg::Matrix mx;

	mx.makeRotate(angle,osg::Vec3(0.0,0.0,1.0));
	mt->setMatrix(mx);
	angle+=0.1;
	traverse(node,nv);
}
