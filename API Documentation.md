class Grid
  Public:
    Functions:
      - Grid()
      - Grid(string catalogFilepath, string componentsListFilepath)
      - ~Grid()
      - gridBus* newBus()
      - loadNode* newLoad()
      - sourceNode* newSource()
      - filterNode* newFilter()
      - esmNode* newESM()
      - void addNewCatalog()
      - void addNewComponent()
    Variables:
      Structs:
        - struct busListElement
          - gridBus* bus
          - double busVoltage

  Private:
    Functions:
      - int findNumCatalogEntries(string catalogFilepath)
      - int findNumComponents(string componentsListFilepath)
    Variables:
      - vector<busListElement*>* busList
      - vector<loadNode*>* loads
      - vector<sourceNode*>* sources
      - vector<filterNode*> filters
      - vector<esmNode*>* ESMs
      - vector<int>* componentsList
      - vector<component*>* activeComponents
      - vector<int>* Catalog
      - commonModeGrid* cmEqModel

class gridNode
  Public:
    Functions:
      - gridNode()
      - ~gridNode()
      - bool validityCheck()

  Private:
    Functions:
      - void loadFromDataFile(string filepath)
    Variables:
      - int serialNumber
      - string name
      - string thumbnailImagePath

  class gridEdge::gridNode
    Public:
      Functions:
        - gridEdge()
        - ~gridEdge()
        - bool validityCheck()

      Private:
        Functions:
          - void loadFromDataFile(string filepath)
        Variables:
          - double voltageA
          - double breakerRating
          - int numPhasesA
          - int numPhasesB
          - double conduit_Diameter
          - double conduit_Capacitance
          - double conduit_Resistance
          - double conduit_Inductance
          - bool pwrTypeA
          - bool pwrTypeB
          - double converter_Capacitance
          - double converter_Resistance
          - double converter_Inductance
          - bool transformer_3pTypeA
          - bool transformer_3pTypeB
          - double transformer_Capacitance
          - double transformer_Resistance
          - double transformer_Inductance

  class gridElement::gridNode
    Public:
      Functions:
        - gridElement()
        - ~gridElement()
        - bool validityCheck()

      Private:
        Functions:
          - void loadFromDataFile(string filepath)
        Variables:
          - int serialNumber
          - string name
          - string thumbnailImagePath

        class sourceNode::gridElement
          Public:
            Functions:
              - sourceNode()
              - ~sourceNode()
              - bool validityCheck()

            Private:
              Functions:
                - void loadFromDataFile(string filepath)
              Variables:
                - int serialNumber
                - string name
                - string thumbnailImagePath

        class loadNode::gridElement
          Public:
            Functions:
              - loadNode()
              - ~loadNode()
              - bool validityCheck()

            Private:
              Functions:
                - void loadFromDataFile(string filepath)
              Variables:
                - int serialNumber
                - string name
                - string thumbnailImagePath

        class esmNode::gridElement
          Public:
            Functions:
              - esmNode()
              - ~esmNode()
              - bool validityCheck()

            Private:
              Functions:
                - void loadFromDataFile(string filepath)
              Variables:
                - int serialNumber
                - string name
                - string thumbnailImagePath

        class filterNode::gridElement
          Public:
            Functions:
              - filterNode()
              - ~filterNode()
              - bool validityCheck()

            Private:
              Functions:
                - void loadFromDataFile(string filepath)
              Variables:
                - int serialNumber
                - string name
                - string thumbnailImagePath

  class gridBus::gridNode
    Public:
      Functions:
        - gridBus()
        - ~gridBus()
        - bool validityCheck()

      Private:
        Functions:
          - void loadFromDataFile(string filepath)
        Variables:
          - int serialNumber
          - string name
          - string thumbnailImagePath

class Component
  Public:
    Functions:
      - Component()
      - ~Component()
      - bool validityCheck()

    Private:
      Functions:
        - void loadFromDataFile(string filepath)
      Variables:
        - int serialNumber
        - string name
        - string thumbnailImagePath

class commonModeGrid
  Public:
    Functions:
      - commonModeGrid()
      - ~commonModeGrid()
      - bool validityCheck()

    Private:
      Functions:
        - void loadFromDataFile(string filepath)
      Variables:
        - int serialNumber
        - string name
        - string thumbnailImagePath
