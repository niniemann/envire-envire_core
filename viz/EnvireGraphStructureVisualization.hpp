#ifndef envire_core_EnvireGraphStructureVisualization_H
#define envire_core_EnvireGraphStructureVisualization_H

#include <boost/noncopyable.hpp>
#include <vizkit3d/Vizkit3DPlugin.hpp>
#include <osg/Geode>
#include <envire_core/graph/EnvireGraph.hpp>
#include <memory>


namespace vizkit3d
{
    class EnvireGraphStructureVisualization
        : public vizkit3d::Vizkit3DPlugin<envire::core::EnvireGraph>
        , boost::noncopyable
    {
    Q_OBJECT
    Q_PROPERTY(QStringList rootNode READ getNodes WRITE setNodes)  

    public:
        EnvireGraphStructureVisualization();
        ~EnvireGraphStructureVisualization();

    Q_INVOKABLE void updateData(envire::core::EnvireGraph const &sample);
    
    QStringList getNodes();
    void setNodes(const QStringList& values);
    
    protected:
        virtual osg::ref_ptr<osg::Node> createMainNode();
        virtual void updateMainNode(osg::Node* node);
        virtual void updateDataIntern(envire::core::EnvireGraph const& plan);
        
    private:
      void initNodeList(envire::core::EnvireGraph const &graph);
        
    private:
        struct Data;
        std::unique_ptr<Data> p;
    };
}
#endif
