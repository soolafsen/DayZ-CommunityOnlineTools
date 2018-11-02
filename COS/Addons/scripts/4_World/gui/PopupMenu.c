class PopupMenu extends ScriptedWidgetEventHandler 
{
    protected ref Widget layoutRoot;
    
    ref BaseWindow baseWindow;

    void PopupMenu() 
    {

    }

    void ~PopupMenu() 
    {
    }

    void OnWidgetScriptInit( Widget w )
    {
        layoutRoot = w;
        layoutRoot.SetHandler( this );

        Init();
    }

    void Init() 
    {

    }

    void Show()
    {
        baseWindow.Show();
        layoutRoot.Show( true );
        OnShow();
    }

    void Hide()
    {
        OnHide();
        layoutRoot.Show( false );
        baseWindow.Hide();
    }

    void OnShow()
    {
    }

    void OnHide() 
    {
    }

    void Update() 
    {
        
    }

    ref Widget GetLayoutRoot() 
    {
        return layoutRoot;
    }

    string GetTitle()
    {
        return "";
    }

    string GetImageSet()
    {
        return "";
    }

    string GetIconName()
    {
        return "";
    }

    bool ImageIsIcon()
    {
        return false;
    }
}