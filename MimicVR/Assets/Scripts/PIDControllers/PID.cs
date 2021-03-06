﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;

/// <summary>
/// Floating point PID.
/// http://forum.unity3d.com/threads/pid-controller.68390/
/// </summary>
[Serializable]
public class PID
{
    // Can also be set externally.
	public float pFactor, iFactor, dFactor;

	float integral;
	float lastError;

    public PID()
    {
    }

    //   public PID(float pFactor, float iFactor, float dFactor)
    //{
    //	this.pFactor = pFactor;
    //	this.iFactor = iFactor;
    //	this.dFactor = dFactor;
    //}


    public float displayPresent;

	public float Update(float setpoint, float actual, float timeFrame)
	{
		float present = setpoint - actual;

        displayPresent = present;

        integral += present * timeFrame;

		float deriv = (present - lastError) / timeFrame;

		lastError = present;

		return present * pFactor + integral * iFactor + deriv * dFactor;
	}
}
