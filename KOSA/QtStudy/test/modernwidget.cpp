#include "ModernWidget.h"
#include "ui_modernwidget.h"
#include <QApplication>

ModernWidget::ModernWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModernWidget)
{
    ui->setupUi(this);

    // 초기값 설정
    ui->valueLineEdit->setText("0");

    // 버튼 시그널 연결
    connect(ui->resetButton, &QPushButton::clicked, this, &ModernWidget::onResetClicked);
    connect(ui->quitButton, &QPushButton::clicked, this, &ModernWidget::onQuitClicked);

    // lineEdit 시그널 연결
    connect(ui->valueLineEdit, &QLineEdit::textChanged, this, &ModernWidget::onLineEditChanged);
    connect(ui->valueLineEdit, &QLineEdit::returnPressed, [this]() {
        onLineEditChanged();
        ui->valueLineEdit->clearFocus();
    });

    // 다이얼 값 변경시 lineEdit 업데이트
    connect(ui->dial, QOverload<int>::of(&QDial::valueChanged), this, &ModernWidget::onDialValueChanged);
}

ModernWidget::~ModernWidget()
{
    delete ui;
}

void ModernWidget::onResetClicked()
{
    ui->dial->setValue(0);
    ui->horizontalSlider->setValue(0);
    ui->valueLineEdit->setText("0");
    ui->valueLineEdit->setStyleSheet(""); // 스타일 리셋
}

void ModernWidget::onQuitClicked()
{
    QApplication::quit();
}

void ModernWidget::onLineEditChanged()
{
    bool ok;
    QString text = ui->valueLineEdit->text();
    int value = text.toInt(&ok);

    if (text.isEmpty()) {
        // 빈 문자열인 경우 스타일 리셋
        ui->valueLineEdit->setStyleSheet("");
        return;
    }

    if (ok && value >= 0 && value <= 100) {
        // 유효한 값인 경우
        ui->valueLineEdit->setStyleSheet(""); // 정상 스타일

        // 다이얼과 슬라이더 업데이트 (무한루프 방지)
        if (ui->dial->value() != value) {
            ui->dial->setValue(value);
        }
        if (ui->horizontalSlider->value() != value) {
            ui->horizontalSlider->setValue(value);
        }
    } else {
        // 유효하지 않은 값인 경우 경고 스타일
        ui->valueLineEdit->setStyleSheet(
            "QLineEdit { border: 2px solid #cc4444; background-color: #2d1a1a; }"
            );
    }
}

void ModernWidget::onDialValueChanged(int value)
{
    // 다이얼 값이 변경될 때 lineEdit 업데이트 (무한루프 방지)
    if (ui->valueLineEdit->text().toInt() != value) {
        ui->valueLineEdit->setText(QString::number(value));
        ui->valueLineEdit->setStyleSheet(""); // 정상 스타일로 리셋
    }
}
