# Qt Tips


## QObject::connect()
五个重载
```
QMetaObject::Connection connect(const QObject *, const char *,
                                const QObject *, const char *,
                                Qt::ConnectionType);

QMetaObject::Connection connect(const QObject *, const QMetaMethod &,
                                const QObject *, const QMetaMethod &,
                                Qt::ConnectionType);

QMetaObject::Connection connect(const QObject *, const char *,
                                const char *,
                                Qt::ConnectionType) const;

QMetaObject::Connection connect(const QObject *, PointerToMemberFunction,
                                const QObject *, PointerToMemberFunction,
                                Qt::ConnectionType)

QMetaObject::Connection connect(const QObject *, PointerToMemberFunction,
                                Functor);
```                               

```
// !!! Qt 5
connect(sender,   signal,
        receiver, slot);
```
这是我们最常用的形式。connect()一般会使用前面四个参数，第一个是发出信号的对象，第二个是发送对象发出的信号，第三个是接收信号的对象，第四个是接收对象在接收到信号之后所需要调用的函数。也就是说，当 sender 发出了 signal 信号之后，会自动调用 receiver 的 slot 函数。

## QValidator

```
QValidator *validator = new QIntValidator(100, 999, this);
QLineEdit *edit = new QLineEdit(this);

// the edit lineedit will only accept integers between 100 and 999
edit->setValidator(validator);```

eg.
```
    //设置QLineEdit只能输入数字，且为0-100
    QIntValidator* validator = new QIntValidator(min, max, this);
    ui->lineEdit->setValidator(validator);
```


## 快捷键

Ctrl+F：在当前编辑窗口查询关键字，可以选择大小写相关，全词匹配，正则表达式匹配，而且在查找之后，还可以进行替换操作。
Ctrl+Shift+F：全局查找，不只局限在当前文件。注意可能会和输入法快捷键冲突，使用时要关闭中文输入法。
Ctrl+Shift+V：剪切板历史列表，你可以通过它选择你之前粘贴过的文字，非常好用。
Ctrl+L：输入数字n，可以快速定位到当前文件的第n行。
Alt+←：后退。
Alt+→：前进。
Ctrl+Home：跳到当前文件开头。
Ctrl+End：跳到当前文件末尾。
Ctrl+Tab：在当前所打开的文件之间切换。
Ctrl+B：编译项目。
Ctrl+R：编译并运行项目。
将鼠标放在某个类上面，然后按Ctrl，这时鼠标会变成小手形状，点击鼠标，这会跳到类的声明处，这是最常用的快捷方式，试着按这样的方法，把鼠标移动到函数上，变量上等等，看看都有什么效果。
F2：移动到定义处。
F4：在头文件和源文件之间切换。
Ctrl+/：注释当前鼠标所在行，如果鼠标选择了多行，则注释多行。
Ctrl+i：选中文本块，Ctrl+i可格式化代码块。
Shift+home|end|←|→：可选中文本。
将鼠标移动到某变量上，右键选择Find Usages（查找引用），这可以查找到这个变量所有被引用的地方，这是个非常好用的功能，一定要牢记。快捷键为Ctrl+Shift+U。
将鼠标移动到某变量上，右键选择Refactor（重构），这个可以帮助你重命名所有引用到的变量，函数。
将鼠标点到某个类上，按F1键，在侧边栏可显示这个类的帮助文档，如果是移动到函数上点击F1键，可显示此函数的帮助信息。再按一次F1，会跳到帮助文档大页面。
关于调试的快捷键你可以在调试菜单中查看，这里就不列举了。


## QPainter::Antialiasing
　抗锯齿（Anti-aliasing）：标准翻译为”抗图像折叠失真“。由于在3D图像中，受分辨的制约，物体边缘总会或多或少的呈现三角形的锯齿，而抗锯齿就是指对图像边缘进行柔化处理，使图像边缘看起来更平滑，更接近实物的物体。它是提高画质以使之柔和的一种方法。如今最新的全屏抗锯齿（FullSceneAnti-Aliasing）可以有效的消除多边形结合处（特别是较小的多边形间组合中）的错位现象，降低了图像的失真度。全景抗锯齿在进行处理时，须对图像附近的像素进行2-4次采样，以达到不同级别的抗锯齿效果。简单的说也就是将图像边缘及其两侧的像素颜色进行混合，然后用新生成的具有混合特性的点来替换原来位置上的点以达到柔化物体外形、消除锯齿的效果。

## QMouseEvent
Mouse events occur when a mouse button is pressed or released inside a widget, or when the mouse cursor is moved.

## QMessageBox::warning
```
[static] int QMessageBox::warning(QWidget *parent, const QString &title, const QString &text, int button0, int button1, int button2 = 0)
```
Opens a warning message box with the given title and text. The dialog may have up to three buttons. If you don't want all three buttons, set the last button, or last two buttons to QMessageBox::NoButton.(if not, the last two buttons will be set to QMessageBox::NoButton)

##  setStatusBar
`setStatusBar(0)`:Setting the status bar to 0 will remove it from the main window

## setSceneRect 
`setSceneRect(-300, -300, 600, 600)`：set a rectangle: x:-300,y:-300,w:600,h:600

