﻿using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LocalMoveCmd : MonoBehaviour, RobotCommandInput {

	Vector3 moveDirection = Vector3.zero;

	Vector3 rotateDirection = Vector3.zero;

	Rigidbody rb;

	[SerializeField]
	float forceMagnitude = 10;

	[SerializeField]
	float torqueMagnitude = .5f;

	public void Backward()
	{
		moveDirection = Vector3.back;
		rotateDirection = Vector3.zero;
	}

	public void Forward()
	{
		moveDirection = Vector3.forward;
		rotateDirection = Vector3.zero;
	}

	public void Left()
	{
		moveDirection = Vector3.zero;
		rotateDirection =new Vector3(0,-1,0);

	}

	public void Right()
	{
		moveDirection = Vector3.zero;
		rotateDirection = new Vector3(0, 1, 0);

	}

	public void Stop()
	{
		moveDirection = Vector3.zero;
		rotateDirection = Vector3.zero;
	}

	// Use this for initialization
	void Start () {
		rb = GetComponent<Rigidbody>();
    }
	
	// Update is called once per frame
	void Update ()
	{
		
		rb.AddRelativeForce( moveDirection * forceMagnitude, ForceMode.Force);
		rb.AddRelativeTorque(rotateDirection * torqueMagnitude, ForceMode.Force);
    }
}