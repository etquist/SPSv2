#ifndef SYSTEMLABEL_H
#define SYSTEMLABEL_H

#include <QLabel>
#include "grid.h"

// This custom label implementation exists to store a pointer back to the
//      corresponding system hierarchy node for unique identification
class systemLabel : public QLabel
{
    Q_OBJECT
public:
    explicit systemLabel(QWidget *parent = nullptr);

    Grid::systemHierNode* refSystemNode;


};

#endif // SYSTEMLABEL_H
