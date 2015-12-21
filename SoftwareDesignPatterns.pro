CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=

TEMPLATE = subdirs

SUBDIRS += \
    AbstractFactoryPattern \
    BuilderPattern \
    FactoryMethodPattern \
    PrototypePattern \
    SingltonPattern \
    AdapterPattern \
    BridgePattern \
    CompositePattern \
    DecoratorPattern \
    FacadePattern \
    FlyweightPattern \
    ProxyPattern \
    ChainOfResponsibilityPattern \
    CommandPattern \
    InterpreterPattern \
    IteratorPattern \
    MediatorPattern \
    MementoPattern \
    ObserverPattern \
    StatePattern \
    StrategyPattern \
    TemplatePattern \
    VisitorPattern

