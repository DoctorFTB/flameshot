// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#include "trolluploadertool.h"
#include "trolluploader.h"
#include <QPainter>

TrollUploaderTool::TrollUploaderTool(QObject* parent)
  : AbstractActionTool(parent)
{}

bool TrollUploaderTool::closeOnButtonPressed() const
{
    return true;
}

QIcon TrollUploaderTool::icon(const QColor& background, bool inEditor) const
{
    Q_UNUSED(inEditor);
    return QIcon(iconPath(background) + "troll-upload.svg");
}
QString TrollUploaderTool::name() const
{
    return tr("Image Uploader to Troll");
}

ToolType TrollUploaderTool::nameID() const
{
    return ToolType::TROLL;
}

QString TrollUploaderTool::description() const
{
    return tr("Upload the selection to Troll");
}

QWidget* TrollUploaderTool::widget()
{
    return new TrollUploader(capture);
}

CaptureTool* TrollUploaderTool::copy(QObject* parent)
{
    return new TrollUploaderTool(parent);
}

void TrollUploaderTool::pressed(const CaptureContext& context)
{
    emit requestAction(REQ_CLEAR_SELECTION);
    capture = context.selectedScreenshotArea();
    emit requestAction(REQ_CAPTURE_DONE_OK);
    emit requestAction(REQ_ADD_EXTERNAL_WIDGETS);
}
