#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WTextEdit.h>

SAMPLE_BEGIN(TextEditors)
auto container = Wt::cpp14::make_unique<Wt::WContainerWidget>();

Wt::WLineEdit *le =
    container->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>());
le->setPlaceholderText("Edit me");

Wt::WLineEdit *out =
    container->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>());
out->setReadOnly(true);

le->keyWentUp().connect([=] {
    out->setText("Line edit: key up event");
});

le->enterPressed().connect([=] {
    out->setText("Line edit: enter pressed event");
});

SAMPLE_END(return container)
