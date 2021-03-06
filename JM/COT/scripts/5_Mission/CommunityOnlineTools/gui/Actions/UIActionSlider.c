class UIActionSlider extends UIActionBase 
{
	protected ref TextWidget m_Label;
	protected ref SliderWidget m_Slider;
	protected ref TextWidget m_Value;

    protected float m_Min;
    protected float m_Max;

    protected float m_StepValue;

    protected float m_Current;

    protected string m_Prepend;
    protected string m_Append;

	override void OnInit() 
	{
		super.OnInit();
        
		m_Label = TextWidget.Cast(layoutRoot.FindAnyWidget("action_label"));
		m_Slider = SliderWidget.Cast(layoutRoot.FindAnyWidget("action"));
		m_Value = TextWidget.Cast(layoutRoot.FindAnyWidget("action_value"));
	}

	override void OnShow()
	{
	}

	override void OnHide() 
	{
	}

    void SetPrepend( string prepend )
    {
        m_Prepend = prepend;
    }

    void SetAppend( string append )
    {
        m_Append = append;
    }

	void SetLabel( string text )
	{
		m_Label.SetText( text );
	}

    void SetStepValue( float step )
    {
        m_StepValue = step;

        CalculateValue();
    }

    void SetMin( float min )
    {
        m_Min = min;

        CalculateValue();
    }

    void SetMax( float max )
    {
        m_Max = max;

        CalculateValue();
    }

    float GetValue()
    {
        return m_Current;
    }

    void SetValue( float value )
    {
        float x = value;
        float a = m_Slider.GetMin();
        float b = m_Slider.GetMax();
        float min = m_Min;
        float max = m_Max;

        float top = ( b - a ) * ( x - min );
        float bottom = ( max - min );

        if ( bottom != 0 )
        {
            m_Slider.SetCurrent( ( top / bottom ) + a );
            CalculateValue();
            return;
        }

        m_Slider.SetCurrent( 0 );
    }

    void CalculateValue()
    {
        float x = m_Slider.GetCurrent();
        float a = m_Min;
        float b = m_Max;
        float min = m_Slider.GetMin();
        float max = m_Slider.GetMax();

        float top = ( b - a ) * ( x - min );
        float bottom = ( max - min );

        if ( bottom != 0 )
        {
            m_Current = ( top / bottom ) + a;

            if ( m_StepValue != 0 )
            {
                m_Current = Math.Round( m_Current / m_StepValue ) * m_StepValue;
            }
        }

        m_Value.SetText( m_Prepend + m_Current + m_Append );
    }

	override bool OnChange( Widget w, int x, int y, bool finished )
	{
		CalculateValue(); 

		if ( !m_HasCallback ) return false;

		if ( w == m_Slider )
		{
			CallEvent( UIEvent.CHANGE );
			return true;
		}
		
		return false;
	}

	override bool CallEvent( UIEvent eid )
	{
		GetGame().GameScript.CallFunctionParams( m_Instance, m_FuncName, NULL, new Param2< UIEvent, ref UIActionSlider >( eid, this ) );

		return false;
    }
}