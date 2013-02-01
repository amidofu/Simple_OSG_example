#include <osg/NodeCallback>
#include <osg/MatrixTransform>

class TestCallback:public osg::NodeCallback
{
public:
	double angle;
	TestCallback();
	virtual void operator()(osg::Node* node,osg::NodeVisitor* nv);
};
