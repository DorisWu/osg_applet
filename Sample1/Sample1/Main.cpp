#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osg/Group>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>
#include <osgViewer/Viewer>
#include <osg/Math>

#if 0

class RotateCallback : public osg::NodeCallback
{
public:
	RotateCallback(double angle = osg::PI_2) : m_angle(angle){}
	virtual void handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		osg::ref_ptr<osgViewer::Viewer> viewer = dynamic_cast<osgViewer::Viewer *>(&ea);
		osg::ref_ptr<osg::MatrixTransform> mt = dynamic_cast<osg::MatrixTransform *>(viewer->getSceneData());

		osg::Matrix m;
		m.makeRotate(osg::Vec3(0.0f, 1.0f, 0.0f), m_angle);
		mt->setMatrix(m);
		m_angle += 0.1;
	}

protected:
	double m_angle;
};
#endif

int main()
{
	osgViewer::Viewer viewer;
	viewer.setSceneData(osgDB::readNodeFile("glider.osg"));
	viewer.realize();
	viewer.run();

	return 0;
}