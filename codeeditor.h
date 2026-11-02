#ifndef CODEEDITOR_H
#define CODEEDITOR_H
#include <QPlainTextEdit>
class QWidget;
class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit CodeEditor(QWidget *parent = nullptr);
    void setLineNumbersVisible(bool visible);
    int lineNumberAreaWidth() const;
    void lineNumberAreaPaintEvent(QPaintEvent *event);
protected:
    void resizeEvent(QResizeEvent *event) override;
private slots:
    void updateLineNumberAreaWidth();
    void updateLineNumberArea(const QRect &rect, int dy);
private:
    QWidget *lineNumberArea;
    bool lineNumbersVisible;
};
#endif
