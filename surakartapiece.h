#ifndef SURAKARTAPIECE_H
#define SURAKARTAPIECE_H

#include <QGraphicsEllipseItem>
#include <QPainter>
#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

#define SIZE 800
#define GAP_SIZE 200

using PieceColorMemoryType = int;
enum class PieceColor : PieceColorMemoryType { BLACK,
                                               WHITE,
                                               YELLOW,
                                               RED,
                                               NONE,
                                               UNKNOWN
};

using SurakartaPlayer = PieceColor;

inline PieceColor ReverseColor(PieceColor color) {
    switch (color) {
    case PieceColor::BLACK:
        return PieceColor::WHITE;
    case PieceColor::WHITE:
        return PieceColor::BLACK;
    default:
        return color;
    }
}

inline std::ostream& operator<<(std::ostream& os, const PieceColor& color) {
    switch (color) {
    case PieceColor::NONE:
        os << ".";
        break;
    case PieceColor::BLACK:
        os << "B";
        break;
    case PieceColor::WHITE:
        os << "W";
        break;
    default:
        os << "?";
        break;
    }
    return os;
}

inline std::istream& operator>>(std::istream& is, PieceColor& color) {
    char ch;
    is >> ch;
    switch (ch) {
    case '.':
        color = PieceColor::NONE;
        break;
    case 'B':
        color = PieceColor::BLACK;
        break;
    case 'W':
        color = PieceColor::WHITE;
        break;
    default:
        color = PieceColor::UNKNOWN;
        break;
    }
    return is;
}

struct SurakartaPosition {
    unsigned int x;
    unsigned int y;
    SurakartaPosition(unsigned int x = 0, unsigned int y = 0)
        : x(x), y(y) {}
    bool operator==(const SurakartaPosition& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator!=(const SurakartaPosition& rhs) const {
        return !(*this == rhs);
    }
};

class SurakartaPiece : public QGraphicsObject
{
    Q_OBJECT
public:
    SurakartaPiece();
    SurakartaPiece(unsigned int x, unsigned int y, PieceColor color);
    SurakartaPiece(SurakartaPosition position, PieceColor color);
    void SetPosition(SurakartaPosition position);
    void SetColor(PieceColor color);
    void setSelect(bool);
    void setFixedColor(PieceColor color);
    void Set(SurakartaPosition position, PieceColor color);
    SurakartaPosition GetPosition() const;
    PieceColor GetColor() const;
    PieceColor GetFixColor() {return fixed_color_;}
    bool GetSelect() const;
    friend std::ostream& operator<<(std::ostream& os, const SurakartaPiece& piece);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void Recover_Color();
    QPointF CoorDinate();
    static unsigned int SQUARE_SIZE;
    static unsigned int BOARD_SIZE;

private:
    SurakartaPosition position_;
    PieceColor color_;
    PieceColor fixed_color_;
    unsigned int r = 180 / BOARD_SIZE;
    bool is_selected;
};

#endif // SURAKARTAPIECE_H
